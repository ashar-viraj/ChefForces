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
        cin >> n >> m;
        int mi = INT_MAX, ma = INT_MIN;
        while (m--)
        {
            cin >> itemp;
            mi = min(mi, itemp);
            ma = max(ma, itemp);
        }
        for (int i = 0; i < n; i++)
            cout << max(abs(i - mi), abs(i - ma)) << ' ';
        cout << endl;
    }
    return 0;
}