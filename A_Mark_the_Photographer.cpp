#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define f first
#define s second
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
        bool valid = true;
        vector<int> v(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<int> a, b;
        i = 0;
        while (i < n)
            a.push_back(v[i++]);
        while (i < 2 * n)
            b.push_back(v[i++]);

        for (int i = 0; i < n; i++)
        {
            if (b[i] - a[i] < m)
                valid = false;
        }
        out(valid);
    }
    return 0;
}