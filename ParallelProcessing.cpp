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
        int a[n], pre[n], suf[n];
        rep(i, 0, n)
        {
            cin >> a[i];
            pre[i] = a[i], suf[i] = a[i];
        }
        for (int i = 1; i < n; i++)
            pre[i] += pre[i - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] += suf[i + 1];
        int ans = pre[n - 1];
        for (int i = 0; i < n - 1; i++)
            ans = min(ans, max(pre[i], suf[i + 1]));
        cout << ans << endl;
    }
    return 0;
}