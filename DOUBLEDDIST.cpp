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
        rep(i, 0, n) cin >> v[i];
        sort(v.begin(), v.end());
        vector<int> diff(n - 1);
        for (int i = 0; i < n - 1; i++)
            diff[i] = v[i + 1] - v[i];
        bool valid = true;
        for (int i = 1; i < n - 1; i++)
        {
            if (diff[i] * 2 == diff[i - 1] || diff[i - 1] * 2 == diff[i])
                continue;
            valid = false;
            break;
        }
        out(valid);
    }
    return 0;
}