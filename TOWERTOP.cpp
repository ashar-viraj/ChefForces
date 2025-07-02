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
        int x, m;
        cin >> x >> m;
        int minMReq = ceil(log2(x)) + 1;
        if (minMReq > m)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            m -= minMReq;
            cout << m + 1 << endl;
        }
    }
    return 0;
}