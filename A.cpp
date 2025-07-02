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

void dfs(vector<vector<int>> &al, vector<bool> &visited, vector<int> &levels, int node, int l)
{
    levels[node] = l;
    visited[node] = true;

    for (auto e : al[node])
        if (!visited[e])
            dfs(al, visited, levels, e, l + 1);
}

void solve(int node, vector<vector<int>> &al, vector<bool> &visited, int &ans, int c, vector<int> &levels)
{
    visited[node] = true;

    int rem = c, size = al[node].size();
    if (node != 1)
        size--;

    if (levels[node] == 1)
        rem--;
    else if (levels[node] >= 2)
        rem -= 2;
    while (size--)
    {
        ans = (ans * rem) % MOD;
        rem--;
    }
    for (auto e : al[node])
        if (!visited[e])
            solve(e, al, visited, ans, c, levels);
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;

    int c;
    cin >> n >> c;
    vector<vector<int>> al(n + 1);
    rep(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;

        al[u].push_back(v);
        al[v].push_back(u);
    }

    vector<int> level(n + 1, 0);
    vector<bool> visited(n + 1, false);

    dfs(al, visited, level, 1, 1);

    int ans = c;

    rep(i, 0, n + 1)
        visited[i] = false;

    solve(1, al, visited, ans, c, level);

    cout << ans << endl;
    return 0;
}