#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
#define f first
#define s second
#define pb push_back
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
        int k, z, ans = 0, sum = 0;
        cin >> n >> k >> z;
        vector<int> v(n), pre;
        for (auto &e : v) {
            cin >> e;
            sum += e;
            pre.push_back(sum);
        }

        for (int i = 1; k-i >= 0; i++)
        {
            int back = z, front = i - back

            // sum += v[i];
            // int remainStep = k - i;
            // int r1 = (remainStep + 1) / 2, r2 = remainStep / 2;
            // if (r1 <= z)
            // {
            //     cout << sum << ' ' << r1 << ' ' << v[i - 1] << ' ' << r2 << ' ' << v[i] << ' ' << sum + (r1 * v[i - 1]) + (r2 * v[i]) << endl;
            //     ans = max(ans, sum + (r1 * v[i - 1]) + (r2 * v[i]));
            // }
        }

        cout << ans << endl;
    }
    return 0;
}

/*
3 2, 1
4 2 2
5 3 2
*/