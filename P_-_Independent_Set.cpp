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
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solve(vector<vector<int>> &al, int node, int color, int par, vector<vector<int>> &dp)
{
    if (dp[node][color] != -1)
        return dp[node][color];

    int ans = 1;

    for (auto e : al[node])
    {
        if (par == e)
            continue;
        if (color == 0)
            (ans *= (solve(al, e, 0, node, dp) + solve(al, e, 1, node, dp)) % MOD) %= MOD;
        else
            (ans *= solve(al, e, 0, node, dp)) %= MOD;
    }

    return dp[node][color] = ans;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> al(n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        al[u].push_back(v);
        al[v].push_back(u);
    }

    vector<vector<int>> dp(n, vector<int>(2, -1));

    int ans = ((solve(al, 0, 0, -1, dp) + solve(al, 0, 1, -1, dp))) % MOD;

    cout << ans << endl;

    return 0;
}