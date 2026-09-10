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

void updateTree(vector<int> &tree, int left, int right, int idx, int node, int val)
{
    if (left == right)
    {
        tree[node] = val;
        return;
    }

    int mid = (left + right) / 2;
    if (idx <= mid)
        updateTree(tree, left, mid, idx, node * 2 + 1, val);
    else
        updateTree(tree, mid + 1, right, idx, node * 2 + 2, val);

    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

int query(vector<int> &tree, int start, int end, int left, int right, int node)
{
    if (end < left || right < start)
        return 0;

    if (start <= left && right <= end)
        return tree[node];

    int mid = (left + right) / 2;

    int leftAns = query(tree, start, end, left, mid, node * 2 + 1);
    int rightAns = query(tree, start, end, mid + 1, right, node * 2 + 2);

    return leftAns + rightAns;
}

void printSegTree(vector<int> &tree)
{
    for(int i = 0 ; i < tree.size(); i++)
    {
        cout << tree[i] << ' ';
        if(((i + 1) & (i + 2)) == 0)
            cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> b(n);
        rep(i, 0, n)
            cin >> b[i];

        // ---- compress shadows: distinct sorted values B[] + their multiplicities cnt[]
        // Since (value <-> shadow) is an order-preserving bijection, the i-th smallest
        // distinct shadow belongs to the i-th smallest distinct value of a.
        vector<int> B;

        map<int, bool> isThere;
        for(auto e : b)
            isThere[e] = true;

        for(auto e : isThere)
            B.push_back(e.first);
        int k = B.size();

        vector<int> cnt(k, 0);
        for(int i = 0; i < n; i++) {
            int pos = lower_bound(B.begin(), B.end(), b[i]) - B.begin();
            cnt[pos]++;
        }

        vector<int> v(k, 0);
        bool isValid = (B[0] == 0);

        for(int i = 0; i < k-1; i++)
        {
            if (!isValid)
                break;
            int diff = B[i + 1] - B[i];
            if (diff % cnt[i] != 0)
            {
                isValid = false;
                break;
            }
            v[i] = diff / cnt[i];
            if (i > 0 && v[i] <= v[i - 1])
            {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            if(k == 1)
                v[k-1] = 1;
            else
                v[k-1] = v[k-2] + 1;
        }

        if (!isValid)
        {
            cout << -1 << endl;
            continue;
        }

        for(int i = 0; i < n; i++) {
            int pos = lower_bound(B.begin(), B.end(), b[i]) - B.begin();
            cout << v[pos] << " ";
        }
        cout << endl;
    }
    return 0;
}