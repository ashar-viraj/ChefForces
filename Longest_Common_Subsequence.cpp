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
#define pb push_back
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (auto &e : a)
        cin >> e;
    for (auto &e : b)
        cin >> e;

    vector<vector<int>> dp(n, vector<int>(m, -1));

    // int ans = solve(a, b, n - 1, m - 1, n, m, dp);

    dp[0][0] = a[0] == b[0];
    for (int i = 1; i < n; i++)
        dp[i][0] = max(dp[i - 1][0], (int)(a[i] == b[0]));

    for (int j = 1; j < m; j++)
        dp[0][j] = max(dp[0][j - 1], (int)(a[0] == b[j]));

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], (a[i] == b[j] ? dp[i - 1][j - 1] + 1 : 0)});

    int ans = dp[n - 1][m - 1];

    int i = n-1, j = m-1;

    vector<int> v;

    while(i > 0 && j > 0 && dp[i][j] > 0) {
        if(dp[i][j-1] == dp[i][j]) {
            j--;
        } else if(dp[i][j] == dp[i-1][j]) {
            i--;
        } else {
            v.push_back(a[i]);
            i--;
            j--;
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    if(i >= 0 && j >= 0 && dp[i][j] > 0) {
        if(i == 0) {
            v.push_back(a[0]);
        } else {
            v.push_back(b[0]);
        }
    }

    cout << ans << endl;

    reverse(v.begin(), v.end());

    for(auto e : v)
        cout << e << ' ';

    return 0;
}