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
        vector<int> v(n);

        rep(i, 0, n)
        {
            cin >> v[i];
        }
        int reqAns = v[0];
        rep(i, 1, n)
            reqAns &= v[i];
        int ans = 0, totalAnd = pow(2, 30) - 1, length = 1;
        for (int i = 0; i < n; i++)
        {
            totalAnd &= v[i];
            if (totalAnd == reqAns)
            {
                ans += (length - 1);
                totalAnd = pow(2, 30) - 1;
                length = 0;
            }
            length++;
        }
        if (totalAnd != reqAns)
            ans += length - 1;
        cout << ans << endl;
    }
    return 0;
}