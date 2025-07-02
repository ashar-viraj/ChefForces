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
        int b[n];
        int a[n];
        rep(i, 0, n)
        {
            cin >> b[i];
            a[i] = -1;
        }
        for (int i = n; i >= 0; i--)
        {
            if (b[i] == -1)
                a[i] = a[i + 1];
            else
                a[i] = b[i] - 1;
        }
        
    }
    return 0;
}