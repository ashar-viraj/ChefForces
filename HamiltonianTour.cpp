#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

bool solve(vector<vector<int>> &mat, int r, int c, int n, int m, string &ans, char prevDir)
{
    if (r == 0 && c == 0 && mat[r][c] == 0)
    {
        return true;
    }
    if (r < 0 || r >= n || c < 0 || c >= m || mat[r][c] == 0)
    {
        return false;
    }
    mat[r][c] = 0;

    if (prevDir == 'E' && solve(mat, r - 1, c, n, m, ans, 'N'))
    {
        ans = 'N' + ans;
    }
    else if (prevDir == 'S' && solve(mat, r, c + 1, n, m, ans, 'E'))
    {
        ans = 'E' + ans;
    }
    else if (prevDir == 'W' && solve(mat, r + 1, c, n, m, ans, 'S'))
    {
        ans = 'S' + ans;
    }
    else if (prevDir == 'S' && solve(mat, r, c - 1, n, m, ans, prevDir))
    {
        ans = 'W' + ans;
    }
    else if (solve(mat, r, c + 1, n, m, ans, 'E'))
    {
        // cout << r << ' ' << c << " E" << endl;
        ans = 'E' + ans;
    }
    else if (solve(mat, r + 1, c, n, m, ans, prevDir))
    {
        // cout << r << ' ' << c << " S" << endl;
        ans = 'S' + ans;
    }
    else if (solve(mat, r, c - 1, n, m, ans, prevDir))
    {
        // cout << r << ' ' << c << " W" << endl;
        ans = 'W' + ans;
    }
    else if (solve(mat, r - 1, c, n, m, ans, prevDir))
    {
        // cout << r << ' ' << c << " N" << endl;
        ans = 'N' + ans;
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        int r, c;
        cin >> r >> c;
        r *= 2, c *= 2;
        vector<vector<int>> mat(r, vector<int>(c, 0));
        vector<string> inp(r / 2);
        for (int i = 0; i < r / 2; i++)
        {
            cin >> inp[i];
        }
        for (int i = 0; i < r / 2; i++)
        {
            for (int j = 0; j < c / 2; j++)
            {
                if (inp[i][j] == '*')
                {
                    mat[2 * i][2 * j] = 1;
                    mat[2 * i][2 * j + 1] = 1;
                    mat[2 * i + 1][2 * j] = 1;
                    mat[2 * i + 1][2 * j + 1] = 1;
                }
            }
        }
        string ans = "";
        solve(mat, 0, 0, r, c, ans, '0');
        bool valid = true;
        cout << endl;
        for (auto e : mat)
        {
            for (auto q : e)
            {
                cout << q << ' ';
                if (q == 1)
                {
                    valid = false;
                }
            }
            cout << endl;
        }
        if (valid)
            cout << ans << endl;
        else
            cout << "IMPOSSIBLE\n";
    }
    return 0;
}