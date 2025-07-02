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

    ll t, i, j, n, itemp, q, m, u, v, Q;
    cin >> n >> m;
    map<ll, set<ll>> friends;
    rep(i, 0, m)
    {
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        friends[u].insert(v);
    }
    cin >> Q;
    ll ans = n;
    map<ll, set<ll>> f = friends;
    rep(i, 0, Q)
    {
        cin >> q;
        if (q == 1)
        {
            cin >> u >> v;
            if (u > v)
                swap(u, v);
            f[u].insert(v);
        }
        else if (q == 2)
        {
            cin >> u >> v;
            if (u > v)
                swap(u, v);
            f[u].erase(v);
        }
        else
        {
            for (auto e : f)
            {
                if (!e.second.empty())
                    ans--;
            }
            cout << ans << endl;
            ans = n;
        }
    }
    return 0;
}