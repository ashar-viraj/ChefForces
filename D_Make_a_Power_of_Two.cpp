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
    // ll p[31];
    vector<ll> p(50);
    rep(i, 0, 30)
    {
        p[i] = (ll)pow(2, i);
    }
    rep(i, 30, 50)
    {
        p[i] = p[i - 1] * 2;
    }
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        string s = to_string(n), t;
        ll ans = INT_MAX, present, k;
        rep(i, 0, 50)
        {
            t = to_string(p[i]);
            k = 0;
            present = 0;
            rep(j, 0, t.size())
            {
                while (s[k] != t[j] && k < s.size())
                {
                    k++;
                }
                if (k == s.size())
                {
                    break;
                }
                present++;
                k++;
            }
            cout << t << endl;
            ans = min(ans, (ll)(s.size() - present + t.size() - present));
        }
        cout << ans << endl;
    }
    return 0;
}