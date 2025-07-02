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
        cin >> n;
        int a[n], b[n - 1];
        int d1, d2;
        unordered_map<int, int> freq;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n - 1) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n - 1);
        d1 = b[n - 2] - a[n - 1], d2 = b[n - 2] - a[n - 2];

        rep(i, 0, n)
            freq[a[i]] = 1;
        for (int i = 0; i < n - 1; i++)
            freq[b[i] - d1] = 0;

        int present = 0;
        for (auto e : freq)
            present += e.second;

        rep(i, 0, n)
            freq[a[i]] = 1;
        for (int i = 0; i < n - 1; i++)
            freq[b[i] - d2] = 0;

        int present2 = 0;
        for (auto e : freq)
            present2 += e.second;
        if (present == 1 && d1 > 0)
        {
            if (present2 == 1 && d2 > 0)
                cout << min(d1, d2) << endl;
            else
                cout << d1 << endl;
        }
        else
            cout << d2 << endl;
    }
    return 0;
}