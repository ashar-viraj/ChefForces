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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e : v)
        cin >> e;

    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(2, 0)));
    int prev = 0, curr = 1;
    int chance = 1;
    if (n % 2)
        chance = 0;

    for (int k = 0; k < n; k++)
    {
        int i = 0, j = k, idx = 0;
        while (i < n && j < n)
        {
            if (i == j)
            {
                if (chance)
                    dp[curr][idx] = {0, v[i]};
                else
                    dp[curr][idx] = {v[i], 0};
            }
            else
            {
                if ((dp[prev][idx + 1][chance] + v[i]) > dp[prev][idx][chance] + v[j])
                {
                    dp[curr][idx] = dp[prev][idx + 1];
                    dp[curr][idx][chance] += v[i];
                }
                else
                {
                    dp[curr][idx] = dp[prev][idx];
                    dp[curr][idx][chance] += v[j];
                }
            }
            i++, j++, idx++;
        }
        prev ^= 1, curr ^= 1;
        chance ^= 1;
    }
    cout << dp[prev][0][0] << endl;
    return 0;
}