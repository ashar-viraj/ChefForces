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
        int a[n];
        rep(i, 0, n) cin >> a[i];
        int b[n];
        unordered_map<int, int> freq;
        freq[a[1] - a[0]]++;
        if ((a[2] - a[0]) % 2 == 0)
            freq[(a[2] - a[0]) / 2]++;
        if ((a[3] - a[0]) % 3 == 0)
            freq[(a[3] - a[0]) / 3]++;
        freq[a[2] - a[1]]++;
        if ((a[3] - a[1]) % 2 == 0)
            freq[(a[3] - a[1]) / 2]++;
        freq[a[3] - a[2]]++;
        int ma = INT_MIN, d = 0;
        for (auto e : freq)
        {
            if (e.second > ma)
                ma = e.second, d = e.first;
        }
        b[0] = a[0];
        for (int i = 1; i < n; i++)
            b[i] = b[i - 1] + d;
        int diff = 0;
        for (int i = 0; i < n; i++)
            diff += a[i] != b[i];
        if (diff <= 1)
        {
            for (int i = 0; i < n; i++)
                cout << b[i] << ' ';
            cout << endl;
            continue;
        }
        b[0] = a[1] - d;
        for (int i = 1; i < n; i++)
            b[i] = b[i - 1] + d;
        for (int i = 0; i < n; i++)
            cout << b[i] << ' ';
        cout << endl;
    }
    return 0;
}