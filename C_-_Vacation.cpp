#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solve(vector<vector<int>> &inp, int i, int count, vector<vector<int>> &dp)
{
    if (i == inp.size())
        return 0;

    if (dp[i][count] != -1)
        return dp[i][count];

    int ans = 0;

    if ((count & 1) == 0)
        ans = max(ans, solve(inp, i + 1, 1, dp) + inp[i][0]);

    if ((count & 2) == 0)
        ans = max(ans, solve(inp, i + 1, 2, dp) + inp[i][1]);

    if ((count & 4) == 0)
        ans = max(ans, solve(inp, i + 1, 4, dp) + inp[i][2]);

    dp[i][count] = ans;

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> inp(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> inp[i][0] >> inp[i][1] >> inp[i][2];

    vector<vector<int>> dp(n, vector<int>(8, -1));

    int ans = solve(inp, 0, 0, dp);

    cout << ans << endl;

    return 0;
}