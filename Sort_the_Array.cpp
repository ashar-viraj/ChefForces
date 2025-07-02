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

void solve(int i, int j, int n, vector<int> &v, vector<int> &fo, vector<int> &lo, int chance, int &ans)
{
    if (i > j)
        return;
    if (lo[v[i]] == fo[v[i]] && lo[v[j]] == fo[v[j]])
    {
        if (v[i] < v[j] && i + 1 == j)
            return;
        ans = -1;
        return;
    }
    if (chance ^ 1)
    {
        if (lo[v[i]] == fo[v[i]])
        {
            if (v[i] < v[i + 1])
            {
                i++;
                solve(i, j, n, v, fo, lo, chance, ans);
            }
            else
                ans = -1;
            return;
        }
        ans++;
        i = lo[v[i]] + 1;
        if(v[i-1] > v[i])
        {
            ans = -1;
            return;
        }
    }
    else
    {
        if (lo[v[j]] == fo[v[j]])
        {
            if (v[j - 1] < v[j])
            {
                j--;
                solve(i, j, n, v, fo, lo, chance, ans);
            }
            else
                ans = -1;
            return;
        }
        ans++;
        j = fo[v[j]] - 1;
        if(v[j] > v[j+1])
        {
            ans = -1;
            return;
        }
    }
    chance ^= 1;
    solve(i, j, n, v, fo, lo, chance, ans);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> v(n), fo(n + 1, -1), lo(n + 1);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (fo[v[i]] == -1)
                fo[v[i]] = i;
            lo[v[i]] = i;
        }

        int i = 0, j = n - 1, ans = 0;
        solve(i, j, n, v, fo, lo, 0, ans);

        cout << ans << endl;
    }
    return 0;
}