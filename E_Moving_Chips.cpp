#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

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
        string a, b;
        cin >> a >> b;
        vector<int> lr1(n, 0), rr1(n, 0), lr2(n, 0), rr2(n, 0);

        int freq = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                lr1[i] = freq + (b[i] == '*');
            else
                lr1[i] = lr1[i - 1] + freq + (b[i] == '*');
            freq += (b[i] == '*') + (a[i] == '*');
        }
        freq = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                lr2[i] = freq + (a[i] == '*');
            else
                lr2[i] = lr2[i - 1] + freq + (a[i] == '*');
            freq += (a[i] == '*') + (b[i] == '*');
        }

        freq = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                rr1[i] = freq + (a[i] == '*');
            else
                rr1[i] = rr1[i + 1] + freq + (a[i] == '*');
            freq += (a[i] == '*') + (b[i] == '*');
        }
        freq = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                rr2[i] = freq + (a[i] == '*');
            else
                rr2[i] = rr2[i + 1] + freq + (a[i] == '*');
            freq += (a[i] == '*') + (b[i] == '*');
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, lr1[i] + rr1[i] - (b[i] == '*'));
            ans = min(ans, lr2[i] + rr2[i] - (a[i] == '*'));
        }
        cout << ans << endl;
    }
    return 0;
}