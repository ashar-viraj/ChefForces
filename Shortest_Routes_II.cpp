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

int MAX = 1e9 * 10000;

int32_t main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dis(n, vector<int>(n, MAX));

    for (int i = 0; i < n; i++)
        dis[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        dis[u][v] = min(dis[u][v],c);
        dis[v][u] = min(dis[v][u],c);
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (dis[u][v] == MAX)
            cout << -1 << endl;
        else
            cout << dis[u][v] << endl;
    }

    return 0;
}