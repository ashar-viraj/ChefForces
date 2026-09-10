#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
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

int solve(int i, int k, int n, bool left, vector<vector<vector<int>>> &dp) {
    if(i == 0 || i == n+1 || k == 1)
        return 1;

    if(dp[i][k][left] != -1)
        return dp[i][k][left];

    int ans;

    if(left)
        ans = (solve(i-1, k-1, n, 0, dp) + solve(i+1, k, n, 1, dp)) % MOD;
    else
        ans = (solve(i+1, k-1, n, 1, dp) + solve(i-1, k, n, 0, dp)) % MOD;

    return dp[i][k][left] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        int k;
        cin >> n >> k;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        cout << solve(1, k, n, 1, dp) << endl;
    }
    return 0;
}