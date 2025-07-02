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

int solve(unordered_map<int, vector<int>> &al, int i, unordered_map<int, int> &longestpath, unordered_map<int, bool> &visited)
{
    if (visited[i])
        return longestpath[i];

    visited[i] = true;
    int ans = 0;

    for (auto e : al[i])
        ans = max(ans, solve(al, e, longestpath, visited) + 1);

    longestpath[i] = ans;

    return ans;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> al;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        al[u].push_back(v);
    }

    unordered_map<int, int> longestPath;
    unordered_map<int, bool> visited;

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, solve(al, i, longestPath, visited));

    cout << ans << endl;

    return 0;
}