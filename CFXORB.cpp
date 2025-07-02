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
        int x;
        cin >> x;
        int bits[32];
        memset(bits, -1, sizeof(bits));
        string s = "";
        itemp = x;
        while (itemp)
        {
            s += (itemp % 2 + '0');
            itemp /= 2;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                bits[i] = 0;
        }
        unordered_map<int, int> freq;
        int reqNum = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bits[i] == 0)
            {
                reqNum |= (1 << i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            itemp = a[i];
            int req = 0;
            for (int i = 0; i < 32; i++)
            {
                if (bits[i] == 0)
                {
                    req |= (itemp & (1 << i));
                }
            }
            freq[req]++;
        }
        int ans = 0;
        for (auto e : freq)
        {
            // cout << e.first << ' ' << e.second << endl;
            ans += e.second*e.second;
        }
        cout << ans << endl;
    }
    return 0;
}