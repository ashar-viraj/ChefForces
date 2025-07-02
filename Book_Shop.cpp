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
    vector<int> price(n), page(n);
    for (auto &e : price)
        cin >> e;
    for (auto &e : page)
        cin >> e;

    int prev = 0, curr = 1;
    vector<vector<int>> dp(2, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            int exclude = dp[prev][j], include = 0;
            if (price[i] <= j)
                include = page[i] + dp[prev][j - price[i]];

            dp[curr][j] = max(include, exclude);
        }
        prev ^= 1;
        curr ^= 1;
    }

    cout << dp[prev][x];

    return 0;
}