#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007

int findAns(unordered_map<int, int> &frozen, int node, int time)
{
    if (frozen[node] == -1 || frozen[node] > time)
        cout << "NO\n";
    else
        cout << "YES\n";
}

void updateAns(unordered_map<int, vector<int>> &al, unordered_map<int, int> &frozen, int time, int n)
{
    if (frozen[n] == -1)
        frozen[n] = time;
    else if (time < frozen[n])
        frozen[n] = time;
    else
        return;

    for (auto e : al[n])
        updateAns(al, frozen, time + 1, e);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp, q, time = 0;
    cin >> n >> m >> q;
    unordered_map<int, vector<int>> al;
    unordered_map<int, int> frozen;
    for (int i = 1; i <= n; i++)
        frozen[i] = -1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }

    while (q--)
    {
        int type, node;
        cin >> type >> node;
        if (type == 1)
        {
            updateAns(al, frozen, time, node);
        }
        else if (type == 2)
        {
            time += node;
        }
        else
        {
            findAns(frozen, node, time);
        }
    }

    return 0;
}