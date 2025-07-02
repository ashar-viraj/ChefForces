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

bool solve(vector<int> &v, int i, int n, vector<bool> &dp)
{
    if (i == n)
    {
        return true;
    }

    if (i > n)
        return false;

    bool ans1 = solve(v, i + v[i] + 1, n, dp), ans = false;
    int j = i;
    while (j < n)
    {
        if (v[j] == (j - i))
        {
            bool ans2 = solve(v, j + 1, n, dp);
            ans = ans | ans1 | ans2;
        }
        j++;
    }

    dp[i] = ans;

    return dp[i];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> v(n);
        rep(i, 0, n)
        {
            cin >> v[i];
        }
        vector<bool> dp(n + 1, false);

        if (n == 1)
        {
            out(v[0] == 1);
            continue;
        }

        bool ans = solve(v, 0, n, dp);
        out(ans);
    }
    return 0;
}