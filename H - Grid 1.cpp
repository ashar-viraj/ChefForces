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

int32_t main()
{
    int n, m;
    cin >> n >> m;

    vector<string> v(n);

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++)
        cin >> v[i];

    dp[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (v[i][j] == '#')
                continue;
            (dp[i][j] += (dp[i + 1][j] + dp[i][j + 1])) %= MOD;
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}