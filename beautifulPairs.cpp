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
        cin >> n;
        vector<ll> v(n);
        map<ll, ll> freq;
        rep(i, 0, n)
        {
            cin >> v[i], freq[v[i]]++;
        }
        ll ans = n * (n - 1);
        for (auto e : freq)
        {
            ans -= e.second * (e.second - 1);
        }
        cout << ans << endl;
    }
    return 0;
}