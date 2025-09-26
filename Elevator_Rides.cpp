#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <algorithm>
#include <queue>
#define int long long int
using namespace std;

const int mod = 1e9 + 7;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void add_self(int &a, int b)
{
    a += b;

    if (a >= mod)
        a -= mod;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &x : nums)
        cin >> x;
    int N = 1 << n;

    pair<int, int> dp[N + 10]; // current  number , remaining space in the current elivator
    for (int i = 0; i < N; i++)
        dp[i] = {21, 0};
    dp[0] = {1, k};
    for (int mask = 0; mask < N; mask++)
    {
        for (int currentPerson = 0; currentPerson < n; currentPerson++)
        {

            // chekc if the ith person left or not left.

            if (!(mask & (1 << currentPerson)))
            {
                int currentElevator = dp[mask].first;
                int currentWeight = dp[mask].second;

                int child = mask | (1 << currentPerson);

                if (dp[mask].first == dp[child].first)
                {
                    dp[child].second = max(dp[child].second, currentWeight - nums[currentPerson]);
                }
                else if ((dp[mask].first + 1) == dp[child].first)
                {
                    if (currentWeight >= nums[currentPerson])
                    {
                        dp[child] = {dp[mask].first, currentWeight - nums[currentPerson]};
                    }
                    else
                    {
                        dp[child].second = max(dp[child].second, k - nums[currentPerson]);
                    }
                }
                else if (dp[mask].first < dp[child].first)
                {
                    if (currentWeight >= nums[currentPerson])
                    {
                        dp[child].first = currentElevator;
                        dp[child].second = currentWeight - nums[currentPerson];
                    }
                    else
                    {
                        dp[child].first = currentElevator + 1;
                        dp[child].second = k - nums[currentPerson];
                    }
                }
            }
        }
    }
    cout << dp[N - 1].first << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    // while(t--) {
    solve();
    // }

    return 0;
}