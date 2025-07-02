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

void solve(vector<vector<int>> &al, int curr, int p, vector<int> &par)
{
    par[curr] = p;

    for (auto e : al[curr])
        if (par[e] == -1)
            solve(al, e, curr, par);
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> al(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        al[u].pb(v);
        al[v].pb(u);
    }

    vector<int> par(n + 1, -1);
    par[1] = 0;
    // solve(al, 1, 0, par);
    queue<int> q;
    q.push(1);
    while(q.size())
    {
        int qs = q.size();
        while(qs--)
        {
            int curr = q.front();
            q.pop();
            for(auto e : al[curr])
            {
                if(par[e] == -1)
                {
                    par[e] = curr;
                    q.push(e);
                }
            }
        }
    }

    if (par[n] == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> ans;
        int curr = n;
        while (curr != 0)
        {
            ans.pb(curr);
            curr = par[curr];
        }
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        for (auto e : ans)
            cout << e << ' ';
    }

    return 0;
}
/*
1 : 2 3 4
2 : 1 3
3 : 1 2
4 : 1 5
5 : 4
*/