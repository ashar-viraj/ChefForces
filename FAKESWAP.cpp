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
        string s, p;
        cin >> s >> p;
        bool one = false, zero = false;
        for (auto e : p)
        {
            if (e == '1')
                one = true;
            else
                zero = true;
        }
        if (one && zero)
            cout << "YES\n";
        else
            out(s == p);
    }
    return 0;
}