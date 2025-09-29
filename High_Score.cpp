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

void fillReachByD(vector<vector<int>> oldAl, vector<bool> &reachByD, int n)
{
    vector<vector<int>> al(n);
    for (int i = 0; i < n; i++)
    {
        for (auto e : oldAl[i])
        {
            al[e].push_back(i);
        }
    }

    queue<int> q;
    q.push(n - 1);

    reachByD[n - 1] = true;
    while (q.size())
    {
        int u = q.front();
        q.pop();

        for (auto v : al[u])
        {
            if (!reachByD[v])
            {
                reachByD[v] = true;
                q.push(v);
            }
        }
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> am(n, vector<int>(n, (int)INT_MIN * 2));
    vector<vector<int>> al(n);
    vector<vector<int>> edges;

    for (int i = 0; i < n; i++)
        am[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;

        am[u][v] = max(am[u][v], c);
        al[u].push_back(v);
        edges.push_back({u, v, c});
    }

    queue<int> q;
    q.push(0);
    vector<bool> reachByS(n, false), reachByD(n, false), reach(n, false);
    reachByS[0] = true;

    while (q.size())
    {
        int u = q.front();
        q.pop();

        for (auto v : al[u])
        {
            if (!reachByS[v])
            {
                reachByS[v] = true;
                q.push(v);
            }
        }
    }

    fillReachByD(al, reachByD, n);

    for (int i = 0; i < n; i++)
        reach[i] = reachByS[i] && reachByD[i];

    vector<int> dist(n, (int)INT_MIN * n);
    dist[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto e : edges)
        {
            int u = e[0], v = e[1], c = e[2];
            if (!reach[u] || !reach[v])
                continue;

            dist[v] = max(dist[u] + c, dist[v]);
        }
    }

    bool isLoop = false;
    for (auto e : edges)
    {
        int u = e[0], v = e[1], c = e[2];
        if (!reach[u] || !reach[v])
            continue;

        if ((dist[u] + c) > dist[v])
            isLoop = true;
    }

    if(isLoop)
        cout << -1;
    else
        cout << dist[n-1];

    return 0;
}