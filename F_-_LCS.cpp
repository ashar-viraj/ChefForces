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

int solve(string &s, string &t, int i, int j, int n, int m)
{
    if (i == n || j == m)
        return 0;

    int ans;
    if (s[i] == t[j])
        ans = 1 + solve(s, t, i + 1, j + 1, n, m);
    else
        ans = max(solve(s, t, i + 1, j, n, m), solve(s, t, i, j + 1, n, m));

    return ans;
}

int32_t main()
{
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    string ans = "";
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (dp[i][j] == (1 + dp[i + 1][j + 1]) && (s[i] == t[j]))
        {
            ans += s[i];
            i++, j++;
        }
        else if (dp[i][j] == dp[i + 1][j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << ans << endl;

    return 0;
}