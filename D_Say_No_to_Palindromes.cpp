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

void update(vector<int> &v, vector<vector<int>> &dp, vector<vector<int>> target)
{
    for (int k = 0; k < 6; k++)
        for (int i = 1; i < v.size(); i++)
            dp[k][i] = dp[k][i - 1] + (v[i] != target[k][i % 3]);
}

int32_t main()
{
    int t = 1, i, j, n, m, itemp;
    // cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> v(n + 1);
        for (int i = 0; i < n; i++)
            v[i + 1] = s[i] - 'a';

        vector<vector<int>> dp(6, vector<int>(n + 1, 0));

        update(v, dp, {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}});

        while (m--)
        {
            int l, r;
            cin >> l >> r;
            int ans = r - l + 1;
            for (int i = 0; i < 6; i++)
                ans = min(ans, dp[i][r] - dp[i][l - 1]);

            cout << ans << endl;
        }
    }
    return 0;
}