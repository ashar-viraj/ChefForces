#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solve(vector<int> &w, vector<int> &v, int i, int W, int n, vector<vector<int>> &dp)
{
    if (i == n || W == 0)
        return 0;

    if (dp[i][W] != -1)
        return dp[i][W];

    int include = 0, exclude = 0;

    exclude = solve(w, v, i + 1, W, n, dp);

    if (W >= w[i])
        include = solve(w, v, i + 1, W - w[i], n, dp) + v[i];

    return dp[i][W] = max(include, exclude);
}

int32_t main()
{
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);

    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= W; j++)
        {
            int include = 0, exclude = 0;

            exclude = dp[i + 1][j];

            if (j - w[i] >= 0)
                include = dp[i + 1][j - w[i]] + v[i];

            dp[i][j] = max(include, exclude);
        }
    }

    cout << dp[0][W];

    return 0;
}