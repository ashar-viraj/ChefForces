#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> v(n);
        vector<int> maxidx;
        rep(i, 0, n)
        {
            cin >> v[i];
        }
        int ma = LONG_MIN;
        int ans = 0;
        for (auto e = 0; e < n; e++)
        {
            if (e != 0)
            {
                int m = v[e - 1];
                for (j = e - 2; j >= 0; j--)
                {
                    if (v[j] < m)
                        break;
                    if (m > v[j])
                        m = v[j];
                }
                ans = max(m * v[e], ans);
            }
            if (e != n - 1)
            {
                int m = v[e + 1];
                for (j = e + 1; j < n; j++)
                {
                    if (v[j] < m)
                        break;
                    if (m > v[j])
                        m = v[j];
                }
                ans = max(m * v[e], ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}