#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, n, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        ll k;
        cin >> n >> k;
        vector<ll> v(n + 1);
        rep(i, 1, n + 1)
        {
            cin >> v[i];
        }
        ll ans = LONG_MIN, comp;
        rep(i, max(n - (ll)(202), (ll)1), n)
        {
            rep(j, i + 1, n + 1)
            {
                comp = i * j;
                comp -= k * (v[i] | v[j]);
                ans = max(comp, ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}