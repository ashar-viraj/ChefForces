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

void dfs(vector<vector<int>> &al, int curr, int par, vector<bool> &visited, vector<int> &group)
{
    group[curr] = par;
    visited[curr] = true;

    for (auto e : al[curr])
        if (!visited[e])
            dfs(al, e, par, visited, group);
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> al(n + 1);
    vector<int> group(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        group[i] = i;

    vector<int> cap;
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        cap.push_back(i);
        dfs(al, i, i, visited, group);
    }
    int size = cap.size();
    cout << size-1 << endl;
    for (int i = 1; i < cap.size(); i++)
    {
        cout << cap[i - 1] << ' ' << cap[i] << endl;
    }

    return 0;
}