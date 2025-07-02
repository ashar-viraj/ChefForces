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

int solve(int node, unordered_map<int, vector<int>> &child, unordered_map<int, int> &ans, int &k)
{
    if (child[node].size() == 0)
    {
        if (k == 0)
        {
            return 0;
        }
        else
        {
            k--;
            ans[node] = 1;
            return 1;
        }
    }

    int childFreq = 0;

    for (auto e : child[node])
    {
        childFreq += solve(e, child, ans, k);
    }
    if (k == 0)
    {
        if (childFreq % 2)
        {
            ans[node] = 1;
            return childFreq + 1;
        }
        else
        {
            ans[node] = 0;
            return childFreq;
        }
    }
    else
    {
        k--;
        if (childFreq % 2)
        {
            ans[node] = 0;
            return childFreq;
        }
        else
        {
            ans[node] = 1;
            return childFreq + 1;
        }
    }
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
        int k;
        cin >> n >> k;
        unordered_map<int, vector<int>> child;
        unordered_map<int, int> freq;
        unordered_map<int, int> ans;

        for (int i = 2; i <= n; i++)
        {
            int par;
            cin >> par;
            child[par].push_back(i);
        }

        solve(1, child, ans, k);
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}