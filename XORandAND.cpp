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
        int a[n];
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int bits[32];
        int dp[32];
        rep(i, 0, 32)
            bits[i] = 0;

        int ans = 0;
        for (int i = 0; i < n; i++)
            bits[(int)log2(a[i])]++;

        rep(i, 0, 32)
            ans += (bits[i] * (bits[i] - 1)) / 2;
        cout << ans << endl;
    }
    return 0;
}