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

int32_t main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &e : v)
        cin >> e;
    // vector<int> prev(x + 1, INT_MAX), curr(x + 1);
    // prev[0] = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     curr[0] = 0;
    //     for (int j = 1; j <= x; j++)
    //     {
    //         int include = INT_MAX, exclude = prev[j];
    //         if (j >= v[i])
    //             include = 1 + min(curr[j - v[i]], prev[j - v[i]]);

    //         curr[j] = min(include, exclude);
    //     }
    //     prev = curr;
    // }

    vector<vector<int>> dp(2, vector<int>(x + 1, INT_MAX));
    dp[0][0] = 0;
    int currRow = 1, prevRow = 0;
    // for (int j = 0; j <= x; j++)
    // {
    //     if (dp[prevRow][j] == INT_MAX)
    //         cout << "-1 ";
    //     else
    //         cout << dp[prevRow][j] << ' ';
    // }
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        dp[currRow][0] = 0;
        for (int j = 1; j <= x; j++)
        {
            int include = INT_MAX, exclude = dp[prevRow][j];
            if (j >= v[i])
                include = 1ll + min(dp[currRow][j - v[i]], dp[prevRow][j - v[i]]);

            dp[currRow][j] = min(include, exclude);
        }
        // for (int j = 0; j <= x; j++)
        // {
        //     if (dp[currRow][j] == INT_MAX)
        //         cout << "-1 ";
        //     else
        //         cout << dp[currRow][j] << ' ';
        // }
        // cout << endl;

        currRow ^= 1;
        prevRow ^= 1;
    }

    if (dp[prevRow][x] > x)
        cout << "-1\n";
    else
        cout << dp[prevRow][x];
    return 0;
}