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
        if (n % 2)
        {
            int ans = (((n - 1) / 2) * ((n + 1) / 2) - ((n + 1) / 2) * ((n + 1) / 2));
            cout << ans << endl;
        }
        else
        {
            int ans = ((n / 2) * (n / 2 + 1) - (n / 2) * (n / 2));
            cout << ans << endl;
        }
    }
    return 0;
}