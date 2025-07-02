#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solve(vector<int> &w, vector<int> &v, int i, int val, int n, vector<vector<int>> dp)
{
    if (val == 0)
        return 0;
    if (i == n)
        return INT_MAX;

    if (dp[i][val] != -1)
        return dp[i][val];

    int exclude = solve(w, v, i + 1, val, n, dp), include = INT_MAX;
    if (v[i] <= val)
        include = solve(w, v, i + 1, val - v[i], n, dp) + w[i];

    return dp[i][val] = min(include, exclude);
}

int findMaxVal(vector<int> &w, vector<int> &v, int n, int W)
{
    int maxVal = 0;
    for (auto e : v)
        maxVal += e;

    vector<vector<int>> dp(n + 1, vector<int>(maxVal + 1, -1));

    for (int i = maxVal; i >= 0; i--)
    {
        int reqw = solve(w, v, 0, i, n, dp);
        if (reqw <= W)
            return i;
    }
}

int32_t main()
{
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);

    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    int ans = findMaxVal(w, v, n, W);

    cout << ans << endl;

    return 0;
}