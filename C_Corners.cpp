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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        vector<string> s(n);
        rep(i, 0, n)
        {
            cin >> s[i];
        }

        int ZeroNum = 0, zeroTwoCrossTwo = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ZeroNum += (s[i][j] == '0');
                if (i + 1 < n && s[i][j] == '0' && s[i + 1][j] == '0')
                    zeroTwoCrossTwo++;

                if (j + 1 < m && s[i][j] == '0' && s[i][j + 1] == '0')
                    zeroTwoCrossTwo++;

                if (i + 1 < n && j + 1 < m && s[i][j] == '0' && s[i + 1][j + 1] == '0')
                    zeroTwoCrossTwo++;

                if (i + 1 < n && j - 1 >= 0 && s[i][j] == '0' && s[i + 1][j - 1] == '0')
                    zeroTwoCrossTwo++;
            }
        }
        int OneNum = n * m - ZeroNum;

        int ans = OneNum;
        // if (ans == 0)
        // {
        //     cout << ans << endl;
        // }
        // cout << "zeto : " << zeroTwoCrossTwo << ' ' << ZeroNum << ' ' << OneNum << " | ";
        if(zeroTwoCrossTwo)
        {
            cout << ans << endl;
        }
        else
        {
            if(ZeroNum)
                cout << ans - 1 << endl;
            else
                cout << ans - 2 << endl;
        }

        /*
        if (OneNum > 0)
        {
            if (ZeroNum == 0)
                cout << ans - 2 << endl;
            else
                cout << ans - 1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
        */
    }
    return 0;
}