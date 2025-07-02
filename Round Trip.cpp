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

void findLoop(vector<vector<int>> &al, int curr, int par, vector<bool> &vis, int &loopStart)
{
    vis[curr] = true;

    for (auto e : al[curr])
    {
        if (!vis[e])
        {
            findLoop(al, e, curr, vis, loopStart);
        }
        else if (e != par)
        {
            loopStart = e;
            break;
        }
        if (loopStart != -1)
            return;
    }
}

void solve(vector<vector<int>> &al, int curr, int p, vector<int> &par, int &loopStart, int &ans)
{
    par[curr] = p;

    for (auto e : al[curr])
    {
        if (par[e] == -1)
        {
            solve(al, e, curr, par, loopStart, ans);
        }
        else if (e != p && e == loopStart)
        {
            if (ans == -1)
                ans = curr;
        }
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> al(n + 1);
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        al[u].pb(v);
        al[v].pb(u);
    }
    vector<bool> vis(n + 1, false);
    int loopStart = -1;
    for (int i = 1; i <= n && loopStart == -1; i++)
        if (!vis[i])
            findLoop(al, i, i, vis, loopStart);

    if (loopStart == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> par(n + 1, -1);
    int ans = -1;
    solve(al, loopStart, loopStart, par, loopStart, ans);

    vector<int> v, path;
    v.pb(loopStart);
    while (ans != loopStart)
    {
        v.pb(ans);
        ans = par[ans];
    }
    v.pb(loopStart);

    cout << v.size() << endl;
    for (auto e : v)
    {
        cout << e << ' ';
    }
    return 0;
}
/*
1: 2 5
2: 1 3 6
3: 2 4 6
4: 3 5 7 8 11
5: 1 4 7
6: 2 3
7: 4 5
8: 4 9 10
9: 8 10
10: 8 9
11: 4
*/