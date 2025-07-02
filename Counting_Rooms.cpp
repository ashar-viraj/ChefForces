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

void dfs(vector<string> &s, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i == n || j == m || s[i][j] == '#')
        return;

    s[i][j] = '#';
    for (int k = 0; k < 4; k++)
        dfs(s, i + x4[k], j + y4[k], n, m);
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &e : s)
        cin >> e;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#')
                continue;
            ans++;
            dfs(s, i, j, n, m);
        }
    }

    cout << ans << endl;

    return 0;
}