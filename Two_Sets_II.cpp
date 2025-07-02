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

long solve(long n, long req, vector<vector<long>> &dp)
{
    if (req <= 0)
        return req == 0;
    if (n == 0)
        return 0;

    if (dp[n][req] != -1)
        return dp[n][req];

    long include = solve(n - 1, req - n, dp), exclude = solve(n - 1, req, dp);

    long ans = (include + exclude) % MOD;

    return dp[n][req] = ans;
}

int32_t main()
{
    int n;
    cin >> n;
    long total = (n * (n + 1)) / 2;
    if (total % 2)
    {
        cout << "0\n";
        return 0;
    }

    long req = total / 2;
    vector<vector<long>> dp(n + 1, vector<long>(req + 1, -1));
    cout << solve(n - 1, req - n, dp);
    return 0;
}