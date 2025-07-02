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

int solve(vector<vector<int>> &mat, int men, int women, int n, vector<vector<int>> &dp)
{
    if (men == 0)
        return 1;

    if (dp[men][women] != -1)
        return dp[men][women];

    int ans = 0;

    int i = men - 1;
    for (int j = 0; j < n; j++)
    {
        if ((women & (1 << j)) && mat[i][j])
            (ans += solve(mat, men - 1, (women ^ (1 << j)), n, dp)) %= MOD;
    }

    return dp[men][women] = ans;
}

int32_t main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    vector<vector<int>> dp(n + 1, vector<int>(1 << n, 0));

    dp[0][0] = 1;

    for (int bitMask = 0; bitMask < (1 << n); bitMask++)
    {
        int men = __builtin_popcount(bitMask);
        for (int i = 1; i <= men; i++)
        {
            int women = bitMask;
            for (int j = 0; j < n; j++)
            {
                if ((women & (1 << j)) && mat[i - 1][j])
                    (dp[i][women] += dp[i - 1][women ^ (1 << j)]) %= MOD;
            }
        }
    }

    cout << dp[n][(1 << n) - 1] << endl;

    // vector<vector<int>> dp(n + 1, vector<int>(1 << n, -1));

    // int ans = solve(mat, n, (1 << n) - 1, n, dp);

    // cout << ans << endl;

    return 0;
}

/*
21
0 0 0 0 0 0 0 1 1 0 1 1 1 1
1 1 1 0 0 1 0 0 0 1 0 0 0 0
0 0 1 1 1 1 0 1 1 0 0 1 0 0
0 1 1 0 1 1 0 1 0 1 0 0 1 0
1 1 0 0 1 0 1 0 0 1 1 1 1 0
0 1 1 0 1 1 1 0 1 1 1 0 0 0
0 1 0 0 0 1 0 1 0 0 0 1 1 1
0 0 0 0 1 1 0 0 1 1 0 0 0 0
0 0 1 0 0 1 0 0 1 0 1 1 0 0
0 0 0 0 1 1 0 0 1 1 1 0 0 0
0 1 1 0 1 1 0 0 1 1 0 0 0 1
0 0 1 0 0 1 1 1 1 0 1 1 0 1
0 1 1 0 0 1 1 1 1 0 0 0 1 0
*/