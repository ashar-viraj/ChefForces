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

int solve(vector<string> &v, int i, int j, int n, vector<vector<int>> &dp)
{
    if (i == n || j == n || v[i][j] == '*')
        return 0;
    if (i == n - 1 && j == n - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = (solve(v, i + 1, j, n, dp) + solve(v, i, j + 1, n, dp)) % MOD;

    return dp[i][j] = ans;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &e : v)
        cin >> e;

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << solve(v, 0, 0, n, dp);

    return 0;
}