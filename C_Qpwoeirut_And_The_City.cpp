#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define f first
#define s second
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solve(vector<int> &v, int i, int n, bool nextChanged, int remain, um<int, um<int, um<int, bool>>> &solved, um<int, um<int, um<int, int>>> &dp)
{
    if (solved[i][nextChanged][remain])
    {
        return dp[i][nextChanged][remain];
    }
    if (remain == 0)
        return 0;
    if (i == 0)
        return -1;

    if ((i + 1) / 2 < remain)
        return -1;

    if (nextChanged)
        return solve(v, i - 1, n, false, remain, solved, dp);

    int ans1 = solve(v, i - 1, n, false, remain, solved, dp);
    int ans2;
    if (v[i] > v[i - 1] && v[i] > v[i + 1])
        ans2 = solve(v, i - 1, n, true, remain - 1, solved, dp);
    else
    {
        int newHeight = max(v[i - 1], v[i + 1]) + 1;
        int oldHeight = v[i];
        v[i] = newHeight;
        ans2 = solve(v, i - 1, n, true, remain - 1, solved, dp) + newHeight - oldHeight;
        v[i] = oldHeight;
    }

    int ans;
    if (ans1 != -1)
        ans = ans1;
    if (ans == -1)
        ans = ans2;
    else if (ans2 != -1)
        ans = min(ans, ans2);

    solved[i][nextChanged][remain] = true;
    dp[i][nextChanged][remain] = ans;
    return ans;
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
        vector<int> v(n);
        rep(i, 0, n) cin >> v[i];

        um<int, um<int, um<int, bool>>> solved;
        um<int, um<int, um<int, int>>> dp;

        int ans = solve(v, n - 2, n, false, (n - 1) / 2, solved, dp);
        cout << ans << endl;
    }
    return 0;
}