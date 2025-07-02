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

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &e : v)
        cin >> e;

    vector<vector<int>> dp(2, vector<int>(m + 2, 0));
    int prev = 0, curr = 1;

    if (v[0] == 0)
        for (int j = 1; j <= m; j++)
            dp[prev][j] = 1;
    else
        dp[prev][v[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for(int j = 0; j <= m+1; j++)
            dp[curr][j] = 0;
        if (v[i] == 0)
            for (int j = 1; j <= m; j++)
                (dp[curr][j] = dp[prev][j - 1] + dp[prev][j] + dp[prev][j + 1]) %= MOD;
        else
            dp[curr][v[i]] = (dp[prev][v[i] - 1] + dp[prev][v[i]] + dp[prev][v[i] + 1]) % MOD;
        prev ^= 1, curr ^= 1;
    }

    if (v[n - 1] == 0)
    {
        int ans = 0;
        for (int j = 1; j <= m; j++)
            (ans += dp[prev][j]) %= MOD;
        cout << ans;
    }
    else
        cout << dp[prev][v[n - 1]];

    return 0;
}