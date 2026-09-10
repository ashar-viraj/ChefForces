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

int solve(vector<vector<int>> &al,
          vector<vector<int>> &range,
          int curr,
          int isRight,
          int par,
          vector<bool> &vis,
          vector<vector<int>> &dp)
{
    if (dp[curr][isRight] != -1)
        return dp[curr][isRight];

    int ans = 0;

    for (auto e : al[curr])
    {
        if (e == par)
            continue;
        int ans1 = abs(range[curr][isRight] - range[e][0]) + solve(al, range, e, 0, curr, vis, dp);
        int ans2 = abs(range[curr][isRight] - range[e][1]) + solve(al, range, e, 1, curr, vis, dp);

        ans += max(ans1, ans2);
    }

    return dp[curr][isRight] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<vector<int>> range(n, vector<int>(2)), dp(n, vector<int>(2, -1));
        for (auto &e : range)
            cin >> e[0] >> e[1];

        vector<vector<int>> al(n);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            al[u].push_back(v);
            al[v].push_back(u);
        }

        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++)
            if (al[i].size() == 1)
            {
                cout << max(solve(al, range, i, 0, -1, vis, dp), solve(al, range, i, 1, -1, vis, dp)) << endl;
                break;
            }
    }
    return 0;
}
