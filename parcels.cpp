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

bool valid(vector<vector<bool>> &visited, int i, int j, int n, int m)
{
    return (i >= 0 && j >= 0 && i < n && j < m && !visited[i][j]);
}

bool valid2(vector<vector<int>> &ans, int i, int j, int n, int m)
{
    return (i >= 0 && j >= 0 && i < n && j < m && ans[i][j] == -1);
}

int findMinDis(vector<vector<int>> &mat, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> ans(n, vector<int>(m, -1));
    queue<int> qx, qy;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j])
                qx.push(i), qy.push(j), ans[i][j] = 0;

    while (qx.size())
    {
        int i = qx.front(), j = qy.front(), dis = ans[i][j];
        qx.pop(), qy.pop();

        for (int k = 0; k < 4; k++)
        {
            if (!valid2(ans, i + x4[k], j + y4[k], n, m))
                continue;

            ans[i + x4[k]][j + y4[k]] = dis + 1;
            qx.push(i + x4[k]), qy.push(j + y4[k]);
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            total = max(ans[i][j], total);

    return total;
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
        cin >> n >> m;
        vector<string> inp(n);
        for (int i = 0; i < n; i++)
            cin >> inp[i];

        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] = (inp[i][j] - '0');

        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    mat[i][j] = 1;
                    int smallAns = findMinDis(mat, n, m);
                    mat[i][j] = 0;
                    if (ans == -1)
                        ans = smallAns;
                    ans = min(ans, smallAns);
                }
            }
        }
        cout << max(ans, 0ll) << endl;
    }
    return 0;
}

/*
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
1 0 0 0 0 0 0

0 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
1 0 0 0 0 0 0 {6}
*/