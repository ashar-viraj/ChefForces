#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

int dp[100000][2];

int solve(int i, int n, int a[], unordered_map<int, int> &nextEven, unordered_map<int, int> &nextOdd, bool changed)
{
    if (i == n - 1)
        return 0;

    if (dp[i][changed] != -1)
        return dp[i][changed];

    int ans = 0, ans1 = INT_MAX, ans2 = INT_MAX;

    if (a[i] % 2)
    {
        if (nextOdd[i] == i)
        {
            if (changed)
            {
                dp[i][changed] = INT_MAX;
                return INT_MAX;
            }
            else
            {
                changed = true;
                ans = 1 + solve(nextEven[i], n, a, nextEven, nextOdd, changed);
                dp[i][1] = ans;
                return ans;
            }
        }
    }
    else
    {
        if (nextEven[i] == i)
        {
            if (changed)
            {
                dp[i][changed] = INT_MAX;
                return INT_MAX;
            }
            else
            {
                changed = true;
                ans = 1 + solve(nextOdd[i], n, a, nextEven, nextOdd, changed);
                dp[i][1] = ans;
                return ans;
            }
        }
    }

    if (a[i] % 2)
        ans1 = 1 + solve(nextOdd[i], n, a, nextEven, nextOdd, changed);
    else
        ans1 = 1 + solve(nextEven[i], n, a, nextEven, nextOdd, changed);

    ans = ans1;

    if (!changed)
    {
        changed = true;
        if (a[i] % 2)
            ans2 = 1 + solve(nextEven[i], n, a, nextEven, nextOdd, changed);
        else
            ans2 = 1 + solve(nextOdd[i], n, a, nextEven, nextOdd, changed);
        dp[i][1] = ans2;
    }
    dp[i][0] = ans;
    if (dp[i][1] < 0)
        return dp[i][0];
    return min(dp[i][0], dp[i][1]);
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        unordered_map<int, int> nextEven, nextOdd;
        int lastOdd = -1, lastEven = -1;
        if (a[n - 1] % 2)
            lastOdd = n - 1;
        else
            lastEven = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] % 2)
            {
                if (lastOdd == -1)
                    nextOdd[i] = i;
                else
                    nextOdd[i] = lastOdd;
                lastOdd = i;
                nextEven[i] = lastEven;
            }
            else
            {
                if (lastEven == -1)
                    nextEven[i] = i;
                else
                    nextEven[i] = lastEven;
                lastEven = i;
                nextOdd[i] = lastOdd;
            }
        }
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        int ans = solve(0, n, a, nextEven, nextOdd, false);
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << dp[i][0] << ' ' << dp[i][1] << endl;
        }
        cout << endl;
        cout << ans << endl;
    }
    return 0;
}