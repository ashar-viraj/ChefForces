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
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> dir(n, vector<char>(m, 'n'));
    um<int, um<int, char>> storeDir;
    storeDir[-1][0] = 'D';
    storeDir[0][1] = 'L';
    storeDir[1][0] = 'U';
    storeDir[0][-1] = 'R';
    um<char, int> retriveDirX = {{'D', 1}, {'L', 0}, {'U', -1}, {'R', 0}}, retriveDirY = {{'D', 0}, {'L', -1}, {'U', 0}, {'R', 1}};

    vector<string> v(n);
    vector<int> start, end;

    queue<int> qx, qy;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
                start = {i, j};
            if (v[i][j] == 'B')
                end = {i, j};
        }
    }
    qx.push(start[0]);
    qy.push(start[1]);
    dir[start[0]][start[1]] = '0';
    bool found = false;

    while (qx.size() && dir[end[0]][end[1]] == 'n')
    {
        int i = qx.front(), j = qy.front();
        qx.pop(), qy.pop();

        for (int k = 0; k < 4; k++)
        {
            int ni = i + x4[k], nj = j + y4[k];
            // cout << i << ' ' << j << " : ";
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && (v[ni][nj] == '.' || v[ni][nj] == 'B') && dir[ni][nj] == 'n')
            {
                // cout << ni << ' ' << nj << " | ";
                qx.push(ni);
                qy.push(nj);

                dir[ni][nj] = storeDir[x4[k]][y4[k]];
            }
            cout << endl;
        }
    }

    if (dir[end[0]][end[1]] == 'n')
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    int i = end[0], j = end[1];
    string ans = "";
    while (v[i][j] != 'A')
    {
        ans += dir[i][j];
        int nexti = i + retriveDirX[dir[i][j]];
        int nextj = j + retriveDirY[dir[i][j]];
        i = nexti;
        j = nextj;
    }

    for(auto &e : ans)
    {
        if(e == 'U')
            e = 'D';
        else if(e == 'D')
            e = 'U';
        else if(e == 'L')
            e = 'R';
        else
            e = 'L';
    }

    reverse(ans.begin(), ans.end());


    cout << ans.size() << '\n' << ans;

    return 0;
}