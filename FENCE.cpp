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
        cin >> n >> m >> k;
        vector<vector<int>> rows(n), cols(m);
        for (int i = 0; i < k; i++)
        {
            int r, c;
            cin >> r >> c;
            rows[r - 1].push_back(c - 1);
            cols[c - 1].push_back(r - 1);
        }
        for (auto e : rows)
            sort(e.begin(), e.end());
        for (auto e : cols)
            sort(e.begin(), e.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < rows[i].size(); j++)
            {
                if (j == 0)
                {
                    ans++;
                }
                if (j == rows.size() - 1)
                {
                    ans++;
                }
                if (j > 0 && j <= rows.size() - 1 && rows.size() > 1 && rows[i][j] - rows[i][j - 1] != 1)
                    ans++;
                if (j >= 0 && j < rows.size() - 1 && rows.size() > 1 && rows[i][j + 1] - rows[i][j] != 1)
                    ans++;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < cols[i].size(); j++)
            {
                if (j == 0)
                    ans++;
                if (j == cols.size() - 1)
                    ans++;
                if (j > 0 && j <= cols.size() - 1 && cols.size() > 1 && cols[i][j] - cols[i][j - 1] != 1)
                    ans++;
                if (j >= 0 && j < cols.size() - 1  && cols.size() > 1 && cols[i][j + 1] - cols[i][j] != 1)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}