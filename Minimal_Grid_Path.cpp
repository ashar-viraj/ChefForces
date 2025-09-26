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
#define pb insert
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &e : s)
        cin >> e;

    // int n = 3000;
    // vector<string> s(n, "");
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         s[i] += 'A';

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    dp[0][0] = true;
    int x, y;
    string ans = "" + s[0].substr(0, 1);

    for (int i = 0; i < n; i++)
    {
        int k = i, l = 0;
        char minChar = 'Z';
        while (k >= 0 && l < n)
        {
            if (!dp[k][l])
            {
                k--, l++;
                continue;
            }
            x = k + 1, y = l;
            if (x < n)
                minChar = min(minChar, s[x][y]);

            x = k, y = l + 1;
            if (y < n)
                minChar = min(minChar, s[x][y]);

            k--, l++;
        }

        k = i, l = 0;
        while (k >= 0 && l < n)
        {
            if (!dp[k][l])
            {
                k--, l++;
                continue;
            }
            x = k + 1, y = l;
            if (x < n && s[x][y] == minChar)
                dp[x][y] = true;

            x = k, y = l + 1;
            if (y < n && s[x][y] == minChar)
                dp[x][y] = true;

            k--, l++;
        }

        ans += minChar;
    }

    for (int j = 1; j < n - 1; j++)
    {
        int k = n - 1, l = j;
        char minChar = 'Z';
        while (k >= 0 && l < n)
        {
            if (!dp[k][l])
            {
                k--, l++;
                continue;
            }
            x = k + 1, y = l;
            if (x < n)
                minChar = min(minChar, s[x][y]);

            x = k, y = l + 1;
            if (y < n)
                minChar = min(minChar, s[x][y]);

            k--, l++;
        }

        k = n - 1, l = j;
        while (k >= 0 && l < n)
        {
            if (!dp[k][l])
            {
                k--, l++;
                continue;
            }
            x = k + 1, y = l;
            if (x < n && s[x][y] == minChar)
                dp[x][y] = true;

            x = k, y = l + 1;
            if (y < n && s[x][y] == minChar)
                dp[x][y] = true;

            k--, l++;
        }

        ans += minChar;
    }

    cout << ans.substr(0, n + n - 1);

    return 0;
}