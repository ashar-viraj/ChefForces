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
        vector<ll> a(n), b(n);
        map<ll, vector<ll>> modidx;
        set<ll> scheck;
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        rep(i, 0, n)
        {
            cin >> b[i];
        }
        rep(i, 0, n)
        {
            modidx[(a[0] + b[i]) % n].push_back(i);
            scheck.insert((a[0] + b[i]) % n);
        }
        ll ans;
        if (modidx[*scheck.begin()].size() == 1)
        {
            i = 0;
            ans = modidx[*scheck.begin()][0];
        }
        else
        {
            i = 0;
            ll minvalue;
            while (i < n)
            {
                i++;
                minvalue = *scheck.begin();
                set<ll> stemp;
                map<ll, vector<ll>> mtemp;
                for (auto e : modidx[minvalue])
                {
                    mtemp[(a[i % n] + b[(e + 1) % n]) % n].push_back((e + 1) % n);
                    stemp.insert((a[i % n] + b[(e + 1) % n]) % n);
                }
                if (mtemp[*stemp.begin()].size() == 1)
                {
                    ans = mtemp[*stemp.begin()][0];
                    break;
                }
                scheck.clear();
                scheck = stemp;
                modidx.clear();
                modidx = mtemp;
            }
        }
        vector<ll> vans(n);
        j = 0;
        ll z = i;
        rep(k, z, n)
        {
            vans[k] = (a[i % n] + b[ans % n]) % n;
            i++;
            ans++;
        }
        rep(k, 0, z)
        {
            vans[k] = (a[i % n] + b[ans % n]) % n;
            i++;
            ans++;
        }
        for (auto e : vans)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}