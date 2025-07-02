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

    ll t, i, j, n, itemp, k;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> k;
        vector<ll> v(n), o(n);
        rep(i, 0, n)
        {
            cin >> v[i];
            o[i] = v[i];
        }
        sort(v.begin(), v.end());
        map<ll, ll> vidx;
        rep(i, 0, n)
        {
            vidx[v[i]] = i;
        }
        rep(i, 0, n)
        {
            o[i] = vidx[o[i]];
            v[i] = vidx[v[i]];
        }
        bool valid = false;
        ll part = 0, maxRange = o[0];
        i = 0;
        while (i < n)
        {
            while (o[i + 1] == o[i] + 1 && i < n - 1)
            {
                i++;
            }
            i++;
            part++;
        }
        if (part <= k)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}