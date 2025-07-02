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
        cin >> n >> m;
        vector<int> v(n);
        rep(i, 0, n) cin >> v[i];
        int j = n - 1;
        sort(v.begin(), v.end());
        while (v[j] == v[n - 1] && j > 0)
            j--;

        // cout << j << " ";
        int add = max(((v[n - 1] - v[j] % m) + m) % m, ((v[j] - v[n - 1] % m) + m) % m);
        int ans1 = v[n - 1] + v[j] + add;
        j = n - 1;
        while ((v[j] - v[n - 1]) % m == 0 && j > 0)
            j--;
        // cout << j << " ";
        add = max(((v[n - 1] - v[j] % m) + m) % m, ((v[j] - v[n - 1] % m) + m) % m);
        ans1 = max(ans1, v[n - 1] + v[j] + add);

        ans1 = max(ans1, v[n - 1] + v[n - 1]);

        cout << ans1 << endl;
    }
    return 0;
}