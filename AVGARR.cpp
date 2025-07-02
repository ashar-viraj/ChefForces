#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int x;
        cin >> n >> x;
        int ans[n];
        for (int i = 0; i < n; i++)
            ans[i] = x;
        int sub = n / 2;
        i = 0, j = n - 1;
        while (sub >= 0)
        {
            ans[i] -= sub;
            ans[j] += sub;
            i++, j--, sub--;
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}