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
        int k;
        cin >> n >> k;
        string s;
        cin >> s;
        int one = 0, zero;
        for (auto e : s)
            one += (e == '1');
        zero = n - one;
        if (one % 2)
        {
            if (k % 2)
            {
                
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            int sets = 0;
            i = 0;
            
        }
    }
    return 0;
}