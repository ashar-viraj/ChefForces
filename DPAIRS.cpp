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
    cin >> n >> m;
    int a[n], b[m];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    int maxIdx = 0, minIdx = 0;
    rep(i, 0, m)
    {
        if (b[i] < b[minIdx])
            minIdx = i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ' ' << minIdx << '\n';
        if (a[i] > a[maxIdx])
            maxIdx = i;
    }
    for (int i = 0; i < m; i++)
    {
        if (i == minIdx)
            continue;
        cout << maxIdx << ' ' << i << endl;
    }
    return 0;
}