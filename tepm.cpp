#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define rep(i, a, b) for (int i = a; i < b; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define impos cout << "-1" << endl
#define acum(x) accumulate(x.begin(), x.end(), 0ll)
#define out(x) cout << x << endl
#define in(x) cin >> x
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>
#define vvi vector<vector<int>>
#define vvpi vector<vector<pii>>
#define f first
#define s second
const int x[4] = {0, -1, 0, 1};
const int y[4] = {-1, 0, 1, 0};
// cout <<"Case #"<< t << ": " << solve() << endl;

int maxSumSubarray(vector<int> &a, int n)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum < 0)
            sum = 0;
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int recursion(vi &a, int start, vi &dp, um<int, int> &freq)
{
    if (start >= a.size())
        return 0;

    if (dp[start] != -1)
        return dp[start];

    int ans1 = recursion(a, start + 1, dp, freq);

    int ans2;
    if (start < (a.size() - 1) && a[start + 1] != (a[start] + 1))
        ans2 = a[start] * freq[a[start]] + recursion(a, start + 1, dp, freq);
    else
        ans2 = a[start] * freq[a[start]] + recursion(a, start + 2, dp, freq);

    dp[start] = max(ans1, ans2);
    return dp[start];
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n) in(a[i]);

    sort(a.begin(), a.end());

    vi dp(n, -1);
    um<int, int> freq;
    rep(i, 0, n) freq[a[i]]++;

    out(recursion(a, 0, dp, freq));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}