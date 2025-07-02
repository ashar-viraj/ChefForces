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

bool compare(vector<int> &a, vector<int> &b)
{
    if (a[1] != b[1])
        return a[1] < b[1];
    if (a[0] != b[0])
        return a[0] < b[0];
    return a[2] < b[2];
}

int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(3));
    v[0] = {0, 0, 0};
    for (int i = 1; i <= n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];

    vector<int> dp(n + 1, 0);

    sort(v.begin(), v.end(), compare);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int low = 0, high = i - 1, reqId = v[i][0] - 1, id = low;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (v[mid][1] <= reqId)
            {
                id = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        dp[i] = max(dp[i - 1], dp[id] + v[i][2]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}