#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
#define f first
#define s second
#define pb push_back
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void updateTree(vector<vector<int>> &tree, int left, int right, int idx, int node, int val)
{
    tree[0][node]++;
    tree[1][node] += val;

    if (left == right)
        return;

    int mid = (left + right) / 2;
    if (idx <= mid)
        updateTree(tree, left, mid, idx, node * 2 + 1, val);
    else
        updateTree(tree, mid + 1, right, idx, node * 2 + 2, val);
}

int query(vector<vector<int>> &tree, int &rem, int &cnt, int left, int right, int node)
{
    if (left == right)
    {
        if (tree[1][node] < rem)
        {
            rem -= tree[1][node];
            cnt += tree[0][node];
            return left + 1;
        }
        return left;
    }

    int mid = (left + right) / 2;

    if (tree[1][node * 2 + 1] < rem)
    {
        rem -= tree[1][node * 2 + 1];
        cnt += tree[0][node * 2 + 1];
        return query(tree, rem, cnt, mid + 1, right, node * 2 + 2);
    }

    return query(tree, rem, cnt, left, mid, node * 2 + 1);
}

void printSegTree(vector<vector<int>> &tree)
{
    for(int i = 0 ; i < tree[0].size(); i++)
    {
        cout << tree[0][i] << ',' << tree[1][i] << ' ';
        if(((i + 1) & (i + 2)) == 0)
            cout << endl;
    }
}

vector<int> getUnique(vector<int> v) {
    sort(v.rbegin(), v.rend());
    map<int, int> mp;
    vector<int> vals;

    for (auto e : v)
        mp[e]++;

    for (auto it : mp)
        vals.push_back(it.first);

    return vals;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;

        vector<int> v(n);
        for(auto &e : v)
            cin >> e;

        vector<int> a(n * m);
        for(auto &e : a)
            cin >> e;

        vector<int> vals = getUnique(a);

        reverse(vals.begin(), vals.end());

        int K = vals.size();
        vector<vector<int>> tree(2, vector<int>(16 * K, 0));

        int ans = m;

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j < m; j++)
            {
                int pos = lower_bound(vals.begin(), vals.end(), a[i * m + j], greater<int>()) - vals.begin();
                updateTree(tree, 0, K - 1, pos, 0, a[i * m + j]);
            }

            int rem = v[i], cnt = 0;
            int pos = query(tree, rem, cnt, 0, K - 1, 0);

            if(pos < K)
                ans = min(ans, cnt + (rem + vals[pos] - 1) / vals[pos]);
        }

        cout << ans << endl;
    }
    return 0;
}