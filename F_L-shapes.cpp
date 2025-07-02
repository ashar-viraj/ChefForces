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
        string stemp = "";
        vector<string> v(n + 2, "");
        for (int i = 0; i < m + 2; i++)
            v[0] += '#';

        for (int i = 1; i <= n; i++)
        {
            cin >> stemp;
            v[i] = "#" + stemp + "#";
        }

        v[n + 1] = v[0];

        bool valid = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (v[i][j] == '.')
                    continue;
                if (v[i - 1][j] == '*' && v[i][j - 1] == '*')
                {
                    for (int k = j - 1; k <= j + 1; k++)
                        if (v[i - 2][k] == '*')
                            valid = false;
                    if (v[i - 1][j - 2] == '*' || v[i - 1][j - 1] == '*' || v[i - 1][j + 1] == '*')
                        valid = false;
                    if (v[i][j - 2] == '*' || v[i][j + 1] == '*')
                        valid = false;
                    for (int k = j - 2; k <= j + 1; k++)
                        if (v[i + 1][k] == '*')
                            valid = false;
                }
                else if (v[i - 1][j] == '*' && v[i][j + 1] == '*')
                {
                    for (int k = j - 1; k <= j + 1; k++)
                        if (v[i - 2][k] == '*')
                            valid = false;
                    if (v[i - 1][j - 1] == '*' || v[i - 1][j + 1] == '*' || v[i - 1][j + 2] == '*')
                        valid = false;
                    if (v[i][j - 1] == '*' || v[i][j + 2] == '*')
                        valid = false;
                    for (int k = j - 1; k <= j + 2; k++)
                        if (v[i + 1][k] == '*')
                            valid = false;
                }
                else if (v[i + 1][j] == '*' && v[i][j - 1] == '*')
                {
                    for (int k = j - 2; k <= j + 1; k++)
                        if (v[i - 1][k] == '*')
                            valid = false;
                    if (v[i][j - 2] == '*' || v[i][j + 1] == '*')
                        valid = false;
                    if (v[i + 1][j - 2] == '*' || v[i + 1][j - 1] == '*' || v[i + 1][j + 1] == '*')
                        valid = false;
                    for (int k = j - 1; k <= j + 1; k++)
                        if (v[i + 2][k] == '*')
                            valid = false;
                }
                else if (v[i + 1][j] == '*' && v[i][j + 1] == '*')
                {
                    for (int k = j - 1; k <= j + 2; k++)
                        if (v[i - 1][k] == '*')
                            valid = false;
                    if (v[i][j - 1] == '*' || v[i][j + 2] == '*')
                        valid = false;
                    if (v[i + 1][j - 1] == '*' || v[i + 1][j + 1] == '*' || v[i + 1][j + 2] == '*')
                        valid = false;
                    for (int k = j - 1; k <= j + 1; k++)
                        if (v[i + 2][k] == '*')
                            valid = false;
                }
                else if((v[i][j+1] == '*' && v[i-1][j+1] == '*') ||
                        (v[i+1][j-1] == '*' && v[i+1][j] == '*') ||
                        
                        (v[+1][j] == '*' && v[i+1][j+1] == '*') ||
                        (v[i-1][j-1] =='*' && v[i][j-1] == '*') ||
                        
                        (v[i][j-1] == '*' && v[i+1][j-1] == '*') ||
                        (v[i-1][j] == '*' && v[i-1][j+1] == '*')||
                        
                        (v[i-1][j-1] == '*' && v[i-1][j] == '*') ||
                        (v[i+1][j+1] == '*' && v[i][j] == '*'))
                    {
                        continue;
                    }
                else
                {
                    valid = false;
                }
            }
        }

        out(valid);
    }
    return 0;
}