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

int solve(int n, int m, vector<vector<int>> &dp)
{
    if (n == m)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    int ans = n * m;

    for (int i = 1; i < n; i++)
        ans = min(ans, 1 + solve(i, m, dp) + solve(n - i, m, dp));
    for (int j = 1; j < m; j++)
        ans = min(ans, 1 + solve(n, j, dp) + solve(n, m - j, dp));

    return dp[n][m] = ans;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            int ans = i*j;
            for (int k = 1; k < i; k++)
                ans = min(ans, 1 + dp[k][j] + dp[i - k][j]);
            for (int k = 1; k < j; k++)
                ans = min(ans, 1 + dp[i][k] + dp[i][j - k]);
            dp[i][j] = ans;
        }
    }

    cout << dp[n][m];

    return 0;
}