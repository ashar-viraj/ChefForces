#include <bits/stdc++.h>
using namespace std;

void unionFind(int node, unordered_map<int, int> &par)
{
    if (par[node] == node)
        return;
    unionFind(par[node], par);
    par[node] = par[par[node]];
}

void updateGroup(int u, int v, unordered_map<int, int> &par, unordered_map<int, int> &group, int count[2])
{
    unionFind(v, par);
    unionFind(u, par);

    if (par[u] == par[v])
        return;

    int oldOdd = 0, oldEven = 0, newOdd = 0, newEven = 0;

    if (group[par[u]] != 1 && group[par[u]] % 2)
        oldOdd++;

    if (group[par[u]] != 1 && group[par[u]] % 2 == 0)
        oldEven++;

    if (group[par[v]] != 1 && group[par[v]] % 2)
        oldOdd++;

    if (group[par[v]] != 1 && group[par[v]] % 2 == 0)
        oldEven++;

    group[par[v]] = group[par[v]] + group[par[u]];

    par[u] = par[v];
    unionFind(v, par);
    unionFind(u, par);

    if (par[u] != par[v] && group[par[u]] != 1 && group[par[u]] % 2)
        newOdd++;

    if (par[u] != par[v] && group[par[u]] != 1 && group[par[u]] % 2 == 0)
        newEven++;

    if (group[par[v]] != 1 && group[par[v]] % 2)
        newOdd++;

    if (group[par[v]] != 1 && group[par[v]] % 2 == 0)
        newEven++;

    count[0] = count[0] - oldOdd + newOdd;
    count[1] = count[1] - oldEven + newEven;

}
int32_t main()
{
    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> v(n);
        unordered_map<int, vector<int>> al;
        unordered_map<int, int> par, group;
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            group[i] = 1;
        }

        int count[2] = {0};

        for (int inp = 1; inp < n; inp++)
        {
            int u, v;
            cin >> u >> v;

            al[u].push_back(v);
            al[v].push_back(u);

            updateGroup(u, v, par, group, count);

            cout << abs(count[1] - count[0]) << ' ';
        }
        cout << endl;
    }
    return 0;
}