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
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    if (n < m)
    {
        swap(n, m);
        swap(a, b);
    }

    vector<vector<int>> dp(2, vector<int>(m + 1, 0));

    int prev = 0, curr = 1;
    for (int j = 0; j <= m; j++)
        dp[prev][j] = j;

    for (int i = 1; i <= n; i++)
    {
        dp[curr][0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[curr][j] = dp[prev][j - 1];
            else
                dp[curr][j] = 1 + min({dp[curr][j - 1], dp[prev][j], dp[prev][j - 1]});
        }
        prev ^= 1;
        curr ^= 1;
    }

    cout << dp[prev][m];

    return 0;
}