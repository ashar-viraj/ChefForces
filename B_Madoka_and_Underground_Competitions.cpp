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
        int k, r, c;
        cin >> n >> k >> r >> c;
        vector<vector<char>> ans(n + 1, vector<char>(n + 1, '.'));

        int rstart = r, cstart = c;
        // cout << "ok\n";
        // continue;

        while (rstart >= -(2 * n))
        {
            int i = rstart, j = cstart;
            while (j > 0 && i <= n)
            {
                if(i > 0 && i <= n && j > 0 && j <= n)
                    ans[i][j] = 'X';
                i++;
                j--;
            }
            i = rstart, j = cstart;
            while (i > 0 && j <= n)
            {
                if(i > 0 && i <= n && j > 0 && j <= n)
                    ans[i][j] = 'X';
                i--;
                j++;
            }

            rstart -= k;
        }

        rstart = r, cstart = c;
        while (rstart <= 2 * n)
        {
            int i = rstart, j = cstart;
            while (j > 0 && i <= n)
            {
                if(i > 0 && i <= n && j > 0 && j <= n)
                    ans[i][j] = 'X';
                i++;
                j--;
            }
            i = rstart, j = cstart;
            while (i > 0 && j <= n)
            {
                if(i > 0 && i <= n && j > 0 && j <= n)
                    ans[i][j] = 'X';
                i--;
                j++;
            }

            rstart += k;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << ans[i][j];
            cout << endl;
        }
        // cout << "ok\n";
    }
    return 0;
}