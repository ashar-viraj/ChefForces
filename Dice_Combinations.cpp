#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    cin >> n;
    int temp[7] = {1, 1, 2, 4, 8, 16, 32};
    if (n <= 6)
    {
        cout << temp[n] << "\n";
    }
    else
    {
        int dp[n + 1];
        rep(i, 0, 7)
            dp[i] = temp[i];
        int itemp;
        rep(i, 7, n + 1)
        {
            itemp = 0;
            for (j = i - 1; j > i - 7; j--)
            {
                itemp += dp[j];
            }
            dp[i] = itemp % 1000000007;
        }
        cout << dp[n] % 1000000007;
    }
    return 0;
}