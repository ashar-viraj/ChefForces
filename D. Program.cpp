#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, m, a, b;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> s;
        string stemp;
        int total = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == '+')
            {
                total++;
            }
            else
            {
                total--;
            }
        }
        int dp[s.size()][s.size()];
        // cout << "ok\n";
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == '-')
            {
                dp[i][i] = -1;
            }
            else
            {
                dp[i][i] = 1;
            }
        }
        for (i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[j] == '-')
                {
                    dp[i][j] = dp[i][j - 1] - 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
            }
            // cout << "\n";
        }
        for (i = 0; i < m; i++)
        {
            cin >> a >> b;
            cout << total - (dp[a - 1][b - 1]) << "\n";
        }
        // for (i = 0; i < s.size(); i++)
        // {
        //     for (int j = 0; j < i; j++)
        //     {
        //         cout << "  ";
        //     }
        //     for (int j = i; j < s.size(); j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
    return 0;
}