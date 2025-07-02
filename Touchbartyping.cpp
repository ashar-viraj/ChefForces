#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        cin >> n;
        vector<int> v;
        rep(i, 0, n)
        {

            cin >> itemp;
            if (i == 0)
                v.push_back(itemp);
            else
            {
                if (v[v.size() - 1] != itemp)
                    v.push_back(itemp);
            }
        }
        n = v.size();

        cin >> m;
        vector<int> b(m);
        vector<vector<int>> key(2600);
        rep(i, 0, m)
        {
            cin >> b[i];
            key[b[i]].push_back(i + 1);
        }

        vector<vector<int>> dp(2550, vector<int>(2550, 0));

        int prevMax = 0;

        for (int i = 1; i < n; i++)
        {
            int ccur = v[i], cprev = v[i - 1];
            for (int j = 0; j < key[ccur].size(); j++)
            {
                int smallCost = INT_MAX;
                for (int k = 0; k < key[cprev].size(); k++)
                {
                    smallCost = min(smallCost, abs(key[ccur][j] - key[cprev][k]) + dp[i - 1][k]);
                }
                dp[i][j] = smallCost;
            }
        }

        int ans = INT_MAX, ccur = v[n - 1];
        for (int i = 0; i < key[ccur].size(); i++)
        {
            ans = min(ans, dp[n - 1][i]);
        }
        cout << ans << endl;
    }
    return 0;
}