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

void updateAns(int node, um<int, unordered_set<int>> &grp, int &ans, vector<int> &val, vector<int> &par, int n)
{
    if (val[node] == 1)
        return;

    if (grp[node].size() == 0)
    {
        val[node] = 1;
        ans--;
        grp[par[node]].erase(node);
    }
    if(node == 1 && val[node] == 1)
        ans = n-1;
}

int32_t main()
{

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<vector<int>> al(n + 1);
        um<int, unordered_set<int>> grp;
        vector<int> par(n + 1, 0), val(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            par[v] = u;
            al[u].push_back(v);
            grp[u].insert(v);
        }

        int q, ans = n - 1;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int node;
                cin >> node;
                updateAns(node, grp, ans, val, par, n);
            }
            else
            {
                cout << ans << endl;
            }
        }
    }
    return 0;
}
/*
1
8
1 2
1 3
2 4
2 5
3 6
3 7
19
2
1 4
2
1 5
2
1 6
2
1 2
2
1 3
2
1 7
2
1 1
2
1 3
2
1 1
2
*/
