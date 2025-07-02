#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007

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
        string s;
        cin >> s;
        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++)
        {
            c0 += (s[i] == '0');
            c1 += (s[i] == '1');
        }
        int ans = min(c0, c1) * 2;
        cout << (ans + (c0 != c1)) << endl;
    }
    return 0;
}