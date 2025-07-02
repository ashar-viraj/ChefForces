#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

double solve(vector<double> &v, int i, int n, int headCount, vector<vector<double>> &dp)
{
    if (i == n)
    {
        if (headCount <= 0)
            return 0;
        return 1;
    }

    if (dp[i][headCount + n] != -1)
        return dp[i][headCount + n];

    double ans = 0;
    double head = solve(v, i + 1, n, headCount + 1, dp) * v[i];
    double tail = solve(v, i + 1, n, headCount - 1, dp) * (1.0 - v[i]);
    ans = head + tail;

    return dp[i][headCount + n] = ans;
}

int32_t main()
{
    int n;
    cin >> n;

    vector<double> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<double>> dp(n, vector<double>(2 * n + 1, -1));

    double ans = solve(v, 0, n, 0, dp);
    cout << ans << endl;

    return 0;
}