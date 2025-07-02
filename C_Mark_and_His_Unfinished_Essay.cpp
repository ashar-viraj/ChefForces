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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        unordered_map<int, char> idx;
        for (int i = 1; i <= n; i++)
            idx[i] = s[i-1];

        vector<pair<int, int>> v(c + 1);
        vector<int> prefix(c + 1);
        v[0].first = 1, v[0].second = n;
        prefix[0] = n;
        for (int i = 1; i <= c; i++)
        {
            cin >> v[i].f >> v[i].s;
            prefix[i] = (v[i].s - v[i].f + 1);
            prefix[i] += prefix[i - 1];
        }

        vector<char> ans(q);
        // cout << endl;
        // for (int i = 0; i <= c; i++)
        // {
        //     cout << v[i].first << ' ' << v[i].second << ' ' << prefix[i] << endl;
        // }
        for (int i = 0; i < q; i++)
        {
            int req;
            cin >> req;

            while (req > n)
            {
                int newReq, relIdx;
                int lieInVIdx = lower_bound(prefix.begin(), prefix.end(), req) - prefix.begin();
                relIdx = v[lieInVIdx].f + (req - prefix[lieInVIdx - 1] - 1);
                req = relIdx;
                string stemp;
                // getline(cin, stemp);
                // cout << req << ' ' << relIdx << ' ' << lieInVIdx << endl;
            }
            ans[i] = idx[req];
        }

        for (auto e : ans)
        {
            cout << e << '\n';
        }
    }
    return 0;
}