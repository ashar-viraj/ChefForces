#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")
#define um unordered_map

int solve(vector<int> &inp, int s, int e, int req, int d, um<int, um<int, um<int, int>>> &dp)
{
    if (s == e)
        return min(abs(req - inp[s]), d - abs(req - inp[s]));
    if (dp[s][e][req] != 0)
        return dp[s][e][req];

    int ans1 = min(abs(req - inp[s]), d - abs(req - inp[s])) + solve(inp, s + 1, e, inp[s], d, dp);
    int ans2 = min(abs(req - inp[e]), d - abs(req - inp[e])) + solve(inp, s, e - 1, inp[e], d, dp);

    dp[s][e][req] = min(ans1, ans2);

    return min(ans1, ans2);
}

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> oldinp(n);
    rep(i, 0, n) cin >> oldinp[i];
    vector<int> inp;
    inp.push_back(oldinp[0]);

    for (int i = 1; i < n; i++)
    {
        if (oldinp[i] != oldinp[i - 1])
        {
            inp.push_back(oldinp[i]);
        }
    }

    um<int, um<int, um<int, int>>> dp;
    n = inp.size();

    int ans = solve(inp, 0, n - 1, 0, d, dp);

    cout << ans << endl;
    
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
        cout << "Case #" << tc << ": ";
        solve();
    } 
    return 0;
}