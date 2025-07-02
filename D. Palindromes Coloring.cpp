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
        int k;
        string s;
        cin >> n >> k;
        cin >> s;
        unordered_map<char, int> freq;
        for (auto e : s)
            freq[e]++;
        int two = 0, one = 0;
        for (auto e : freq)
        {
            two += (e.second / 2);
            one += (e.second % 2);
        }
        int ans = 0;
        ans += (two / k);
        two %= k;
        if (two + one >= k)
        {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}