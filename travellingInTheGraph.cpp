#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007

void dfs(int source, int &minVertex, unordered_map<ll, vector<ll>> &am, unordered_map<ll, bool> &visited, unordered_map<ll, ll> &minReachable)
{
    visited[source] = true;
    minVertex = min(minVertex, source);

    for(auto itr = am[source].rbegin(); itr != am[source].rend(); itr++)
    {
        if(visited[*itr])
            continue;
        dfs(source, minVertex, am, visited, minReachable);

    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        unordered_map<ll, vector<ll>> am;
        unordered_map<ll, bool> visited;
        for (ll i = 0; i < n; i++)
            visited[i] = false;
        for (int i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            am[u].push_back(v), am[v].push_back(u);
        }
        for (ll i = n; i >= 1; i--)
        {
            if (visited[i])
                continue;
            int minVertex = i;
            dfs(i, minVertex, am, visited);
        }
    }
    return 0;
}