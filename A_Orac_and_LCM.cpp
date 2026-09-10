#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
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
    for (int i = 0; i < tree.size(); i++)
    {
        cout << tree[i] << ' ';
        if (((i + 1) & (i + 2)) == 0)
            cout << endl;
    }
}

void setPrimeFactors(int N, map<int, vector<int>> &freq)
{
    int n = N, i = 3;
    map<int, int> f;
    while (n % 2 == 0)
    {
        n /= 2;
        f[2]++;
    }
    while (i * i <= N)
    {
        while (n % i == 0)
        {
            f[i]++;
            n /= i;
        }
        i += 2;
    }
    if (n > 1)
        f[n]++;
    for (auto e : f)
        freq[e.first].push_back(e.second);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, i, j, n, m, itemp;
    // cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> v(n);
        vector<vector<int>> primeFact(200000);
        map<int, vector<int>> freq;
        for (auto &e : v)
        {
            cin >> e;
            setPrimeFactors(e, freq);
        }

        int ans = 1;
        for (auto &e : freq)
        {
            sort(e.second.begin(), e.second.end());
            if(e.second.size() == n-1)
                ans *= pow(e.first, e.second[0]);
            else if(e.second.size() == n)
                ans *= pow(e.first, e.second[1]);
        }

        cout << ans << endl;
    }
    return 0;
}