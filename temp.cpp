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

int solve(vector<int> &v, int n, int rem, vector<int> &dp)
{
    if (rem <= 0)
        return rem == 0;

    if (dp[rem] != -1)
        return dp[rem];

    int ans = 0;
    for (int i = 0; i < n; i++)
        (ans += solve(v, n, rem - v[i], dp)) %= MOD;

    return dp[rem] = ans;
}

int32_t main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &e : v)
        cin >> e;

    vector<int> dp(x + 1, -1);
    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        int ans = 0;
        for (int j = 0; j < n; j++)
            if (i >= v[j])
                (ans += dp[i - v[j]]) %= MOD;

        dp[i] = ans;
    }

    cout << dp[x];

    return 0;
}