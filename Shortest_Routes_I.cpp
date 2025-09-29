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

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> al(n);
    map<int, map<int, int>> am;

    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        al[u].push_back(v);

        if(am[u][v] == 0)
            am[u][v] = c;
        am[u][v] = min(am[u][v], c);
    }

    vector<bool> vis(n, false);
    vector<int> dis(n, LONG_MAX);
    dis[0] = 0;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    pq.push({0, 0});

    while (pq.size())
    {
        auto top = pq.top();
        pq.pop();
        int c = top[0], u = top[1];

        if (vis[u])
            continue;

        vis[u] = true;

        for (auto v : al[u])
        {
            if (!vis[v] && (dis[u] + am[u][v]) < dis[v])
            {
                dis[v] = dis[u] + am[u][v];
                pq.push({dis[u] + am[u][v], v});
            }
        }
    }

    for (auto e : dis)
        cout << e << ' ';

    return 0;
}