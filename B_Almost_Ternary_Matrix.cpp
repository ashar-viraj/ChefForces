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
    int put[4][4] = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}};
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        vector<vector<int>> ans(n, vector<int>(m));

        int r = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[i][j] = put[i % 4][j % 4];

        for (auto e : ans)
        {
            for (auto q : e)
            {
                cout << q << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}