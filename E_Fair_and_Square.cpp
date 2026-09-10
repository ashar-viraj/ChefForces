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

void dfs(int node, int par,
         vector<vector<int>> &al,
         vector<int> &subtreeSize,
         vector<int> &parent)
{
    parent[node] = par;
    subtreeSize[node] = 1;

    for (int child : al[node])
    {
        if (child == par)
            continue;

        dfs(child, node, al, subtreeSize, parent);
        subtreeSize[node] += subtreeSize[child];
    }
}

int getAns(vector<unordered_map<int, int>> &neighbours, int curr)
{
    vector<int> nei;
    for (auto e : neighbours[curr])
        nei.push_back(e.second);

    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int x : nei)
    {
        sum3 += sum2 * x;
        sum2 += sum1 * x;
        sum1 += x;
    }

    return sum2 + sum3;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> val(n);
        for (auto &e : val)
            cin >> e;

        vector<vector<int>> al(n);

        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;

            al[u].push_back(v);
            al[v].push_back(u);
        }

        vector<int> parent(n), subtreeSize(n);
        dfs(0, -1, al, subtreeSize, parent);

        vector<unordered_map<int, int>> neighbours(n);

        for (int u = 0; u < n; u++)
        {
            for (int v : al[u])
            {
                if (v == parent[u])
                    neighbours[u][v] = n - subtreeSize[u];
                else
                    neighbours[u][v] = subtreeSize[v];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int sqr = sqrt(val[i]);
            if (sqr * sqr != val[i])
                continue;
            ans += getAns(neighbours, i);
        }

        cout << ans << endl;
    }

    return 0;
}