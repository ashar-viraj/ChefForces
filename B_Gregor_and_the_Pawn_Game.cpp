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
        string a, b;
        cin >> n;
        cin >> a >> b;
        ll ans = 0;
        rep(i, 0, a.size())
        {
            if (a[i] == '0')
            {
                if (b[i] == '1')
                {
                    ans++;
                    b[i] = '0';
                }
            }
            else
            {
                if (i == 0)
                {
                    if (b[1] == '1')
                    {
                        ans++;
                        a[0] = '0';
                        b[1] = '0';
                    }
                }
                else if (i == n - 1)
                {
                    if (b[n - 2] == '1')
                    {
                        ans++;
                        a[n - 1] = '0';
                        b[n - 2] = '0';
                    }
                }
                else
                {
                    if (b[i - 1] == '1')
                    {
                        b[i - 1] = '0';
                        a[i] = '0';
                        ans++;
                    }
                    else if (b[i + 1] == '1')
                    {
                        b[i + 1] = '0';
                        a[i] = '0';
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}