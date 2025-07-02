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
        int q;
        cin >> n >> q;
        vector<int> v(n);
        rep(i, 0, n)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (int i = 1; i < n; i++)
            v[i] += v[i - 1];
        unordered_map<int, int> idx;
        i = 0;
        for (auto e : v)
            idx[e] = i++;
        while (q--)
        {
            cin >> m;
            if(m > v[n-1])
            {
                cout << "-1\n";
                continue;
            }
            auto itr = lower_bound(v.begin(), v.end(), m);
            if (itr == v.end())
            {
                cout << "-1\n";
            }
            else
            {
                cout << idx[*itr] + 1 << endl;
            }
        }
    }
    return 0;
}