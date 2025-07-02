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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        if (n % 2)
        {
            if (n == 1 || n == 3)
                cout << "-1\n";
            else
            {
                cout << "2 3 5 1 4 ";
                for (int i = 6; i < n; i += 2)
                    cout << i << ' ' << i + 2 << ' ';
                cout << endl;
            }
        }
        else
        {
            for (int i = 1; i < n; i += 2)
                cout << i + 1 << ' ' << i << " ";
            cout << endl;
        }
    }
    return 0;
}
