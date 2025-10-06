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

void Dijkstra(vector<vector<vector<int>>> &al, int n, int s, vector<int> &dist)
{
    vector<int> vis(n, false);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    pq.push({0, s});
    dist[s] = 0;

    while (pq.size())
    {
        auto top = pq.top();
        pq.pop();
        int cost = top[0], u = top[1];

        if (vis[u])
            continue;

        vis[u] = true;

        for (auto e : al[u])
        {
            int v = e[0], weight = e[1];
            if (vis[v])
                continue;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> al(n), alR(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, c;

        cin >> u >> v >> c;
        u--, v--;

        al[u].push_back({v, c});
        alR[v].push_back({u, c});
    }

    vector<int> distS(n, n * 2 * INT_MAX), distD(n, n * 2 * INT_MAX);

    Dijkstra(al, n, 0, distS);
    Dijkstra(alR, n, n - 1, distD);

    int ans = n * 2 * INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (auto edges : al[i])
        {
            int cost = distS[i] + edges[1] / 2 + distD[edges[0]];
            ans = min(ans, cost);
        }
    }

    cout << ans;

    return 0;
}