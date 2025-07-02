#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        ll a[n], sum = 0;
        ll pre[n], suf[n];
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        rep(i, 0, n)
            pre[i] = suf[i] = a[i];
        for (int i = 1; i < n; i++)
            pre[i] += pre[i - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] += suf[i + 1];
        bool valid = false;
        ll red = n - 1, blue = 0;
        while (blue < red)
        {
            if (suf[red] > pre[blue] && (blue + 1) > (n - red))
            {
                valid = true;
                break;
            }
            if (pre[blue] >= suf[red])
            {
                red--;
            }
            else if ((blue + 1) <= (n - red))
            {
                blue++;
            }
        }
        if (valid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}