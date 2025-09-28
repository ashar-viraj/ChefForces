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
map<int, char> DIR = {{0, 'U'},
                      {1, 'R'},
                      {2, 'D'},
                      {3, 'L'}};

map<char, int> DIR_IDX = {{'U', 2},
                          {'R', 3},
                          {'D', 0},
                          {'L', 1}};

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);

    int ax, ay;

    for (auto &e : s)
        cin >> e;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'A')
                ax = i, ay = j;

    if(ax == 0 || ax == n - 1 || ay == 0 || ay == m - 1) {
        cout << "YES\n0";
        return 0;
    }

    queue<int> qx, qy;
    vector<vector<int>> mSteps(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'M')
            {
                qx.push(i);
                qy.push(j);

                mSteps[i][j] = 0;
            }
        }
    }

    while (qx.size())
    {
        int x = qx.front();
        int y = qy.front();

        qx.pop();
        qy.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + x4[k];
            int ny = y + y4[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && (s[nx][ny] == '.' || s[nx][ny] == 'A') && mSteps[nx][ny] == INT_MAX)
            {
                mSteps[nx][ny] = mSteps[x][y] + 1;

                qx.push(nx);
                qy.push(ny);
            }
        }
    }

    vector<vector<char>> dir(n, vector<char>(m, ' '));
    vector<vector<int>> steps(n, vector<int>(m, INT_MAX));
    steps[ax][ay] = 0;

    qx.push(ax);
    qy.push(ay);

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << (mSteps[i][j] == INT_MAX ? "." : to_string(mSteps[i][j])) << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    while (qx.size())
    {
        int x = qx.front();
        int y = qy.front();

        qx.pop();
        qy.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + x4[k];
            int ny = y + y4[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && s[nx][ny] == '.' && dir[nx][ny] == ' ' && mSteps[nx][ny] > steps[x][y] + 1)
            {
                dir[nx][ny] = DIR[k];
                steps[nx][ny] = steps[x][y] + 1;

                qx.push(nx);
                qy.push(ny);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << (steps[i][j] == INT_MAX ? "." : to_string(steps[i][j])) << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int nx = -1, ny = -1;
    for (int i = 0; i < n; i++)
    {
        if (dir[i][0] != ' ')
            nx = i, ny = 0;
        if (dir[i][m - 1] != ' ')
            nx = i, ny = m - 1;
    }

    for (int j = 0; j < m; j++)
    {
        if (dir[0][j] != ' ')
            nx = 0, ny = j;
        if (dir[n - 1][j] != ' ')
            nx = n - 1, ny = j;
    }

    if (nx == -1)
    {
        cout << "NO";
        return 0;
    }

    // cout << nx << ' ' << ny << endl;

    cout << "YES\n";
    cout << steps[nx][ny] << endl;

    string ans = "";
    while (nx != ax || ny != ay)
    {
        ans += dir[nx][ny];
        // cout << dir[nx][ny] << ' ';
        // cout << nx << ' ' << ny << endl;

        int newNx = nx + x4[DIR_IDX[dir[nx][ny]]], newNy = ny + y4[DIR_IDX[dir[nx][ny]]];

        nx = newNx, ny = newNy;
    }
    // cout << ax << ' ' << ay << ' ';
    // cout << dir[ax][ay];
    // cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << ((dir[i][j] == ' ') ? '-' : dir[i][j]) << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << nx << ' ' << ny << endl;
    // ans += dir[nx][ny];

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}