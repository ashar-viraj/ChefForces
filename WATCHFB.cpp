#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

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
        int prev[2] = {0, 0};
        for (int i = 0; i < n; i++)
        {
            int q;
            int s[2];
            cin >> q >> s[0] >> s[1];
            sort(s, s + 2);
            if (q == 1)
            {
                if (prev[0] <= s[0] && prev[1] <= s[1])
                {
                    prev[0] = s[0], prev[1] = s[1];
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
            else
            {
                if (s[0] >= prev[1])
                {
                    out(s[0] == s[1]);
                    prev[0] = s[0], prev[1] = s[1];
                }
                else
                {
                    if (prev[0] <= s[0] && prev[1] <= s[1])
                    {
                        out(true);
                        prev[0] = s[0], prev[1] = s[1];
                    }
                    else
                    {
                        out(false);
                    }
                }
            }
        }
    }
    return 0;
}