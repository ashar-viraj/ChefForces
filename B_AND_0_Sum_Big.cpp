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

    int t, i, j, n, itemp, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int ans = 1;
        rep(i, 0, k)
        {
            ans = (ans * n) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}