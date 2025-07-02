/*
1 3
2 3
3 9
3 5
4 9
5 8
*/

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

int solve(vector<vector<int>> &v, int i, int n, vector<int> &dp)
{
    if (dp[i] != -1)
        return dp[i];

    int exclude = 0, include = 1;
    exclude = solve(v, i + 1, n, dp);

    int low = i + 1, high = n - 1, req = v[i][1], idx = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (v[mid][0] >= req)
        {
            idx = min(idx, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (idx != -1)
        include = 1 + solve(v, idx, n, dp);

    return dp[i] = max(include, exclude);
}

int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    vector<int> dp(n + 1, -1);
    dp[n] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }

    sort(v.begin(), v.end());

    int ans = solve(v, 0, n, dp);

    cout << ans;
    return 0;
}