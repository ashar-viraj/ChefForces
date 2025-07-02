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
    vector<vector<int>> al(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        al[u].pb(v);
        al[v].pb(u);
    }

    vector<int> team(n + 1, -1);

    bool valid = true;
    for (int i = 1; i <= n && valid; i++)
    {
        if (team[i] != -1)
            continue;
        queue<int> q;
        q.push(i);
        team[i] = 0;
        while (q.size() && valid)
        {
            int qs = q.size();
            while ((qs--) && valid)
            {
                int curr = q.front();
                q.pop();
                for (auto e : al[curr])
                {
                    if (team[e] == -1)
                    {
                        team[e] = team[curr] ^ 1;
                        q.push(e);
                    }
                    else if (team[e] == team[curr])
                    {
                        valid = false;
                        break;
                    }
                }
            }
        }
    }

    if (valid)
    {
        for (int i = 1; i <= n; i++)
            cout << team[i] + 1 << ' ';
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}