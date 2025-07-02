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

// subarray sum, cost
pair<int, int> solve(vector<int> &v, int i, int j, vector<vector<pair<int, int>>> &dp)
{
    if (i > j)
        return {0, 0};
    if (i == j)
        return {v[i], 0};

    if (dp[i][j].f != -1)
        return dp[i][j];

    pair<int, int> ans = {LONG_LONG_MAX, LONG_LONG_MAX};

    for (int k = i; k < j; k++)
    {
        auto leftAns = solve(v, i, k, dp);
        auto rightAns = solve(v, k + 1, j, dp);

        int newCost = leftAns.f + rightAns.f + leftAns.s + rightAns.s;

        if (newCost < ans.second)
            ans = {leftAns.f + rightAns.f, newCost};
    }

    return dp[i][j] = ans;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }

    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, pair<int, int>(-1, -1)));

    auto ans = solve(v, 0, n - 1, dp);

    cout << ans.s;
    return 0;
}