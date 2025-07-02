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

int solve(vector<int> &v, int n, int rem)
{
    if (rem <= 0)
        return rem == 0;
    if (n == 0)
        return 0;

    int ans = solve(v, n - 1, rem) + solve(v, n, rem - v[n - 1]);

    return ans;
}

int32_t main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &e : v)
        cin >> e;

    int prev = 0, curr = 1;
    vector<vector<int>> dp(2, vector<int>(x + 1, 0));
    dp[prev][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[curr][j] = dp[prev][j];
            if (j >= v[i])
                dp[curr][j] += dp[curr][j - v[i]];
            dp[curr][j] %= MOD;
        }

        prev ^= 1;
        curr ^= 1;
    }

    cout << dp[prev][x];

    return 0;
}