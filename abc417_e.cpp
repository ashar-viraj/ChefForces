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

bool solve(vector<vector<int>> &al, int curr, int des, vector<bool> &vis, vector<int> &ans)
{
    if (curr == des)
    {
        for (auto e : ans)
            cout << e << ' ';
        cout << des << endl;
        return true;
    }

    vis[curr] = true;
    ans.pb(curr);
    for (auto e : al[curr])
    {
        if (!vis[e])
            if (solve(al, e, des, vis, ans))
                return true;
    }
    ans.pop_back();
    vis[curr] = false;

    return false;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        vector<vector<int>> al(n + 1);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            al[u].pb(v);
            al[v].pb(u);
        }

        for (auto &e : al)
            sort(e.begin(), e.end());

        vector<bool> vis(n + 1, false);

        vector<int> ans;
        solve(al, x, y, vis, ans);
    }
    return 0;
}