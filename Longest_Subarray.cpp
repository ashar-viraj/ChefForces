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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<vector<int>> bit(n, vector<int>(32, 0)), prefix, suffix;
        vector<int> totalBit(32, 0), fo(n, -1), lo(n, -1);
        vector<int> v(n);
        rep(i, 0, n)
        {
            cin >> v[i];

            int val = v[i], j = 0;
            while (val)
            {
                if (val & 1)
                {
                    bit[i][j] = 1;
                    totalBit[j]++;
                }
                val /= 2;
                j++;
            }
        }

        // prefix = bit, suffix = bit;
        // for (int i = 1; i < n; i++)
        //     for (int j = 0; j < 32; j++)
        //         prefix[i][j] += prefix[i - 1][j];

        // for (int i = n - 2; i >= 0; i--)
        //     for (int j = 0; j < 32; j++)
        //         suffix[i][j] += suffix[i + 1][j];

        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < 32;j++)
                if(bit[i][j])
                    lo[i] = j;
            for(int j= n-1; j >= 0; j--)
                if()
        }

        int ans = -1;
        int i = 0, j = 0;
        vector<int> curr(32, 0);
        while (j < n)
        {
            bool overflow = false;
            for (int k = 0; k < 32; k++)
                if ((curr[k] + bit[j][k]) > 0 && (curr[k] + bit[j][k]) == totalBit[k])
                    overflow = true;

            if (overflow)
            {
                for (int k = 0; k < 32; k++)
                    curr[k] -= bit[i][k];
                i++;
                continue;
            }

            for (int k = 0; k < 32; k++)
                curr[k] += bit[j][k];

            bool isEqual = true;

            for (int k = 0; k < 32; k++)
            {
                if (curr[k] == 0 && totalBit[k] == 0)
                    continue;
                if (curr[k] != totalBit[k])
                    continue;
                isEqual = false;
            }

            if (isEqual && (j - i + 1) != 0)
                ans = max(ans, j - i + 1);
            j++;
        }

        cout << ans << endl;
    }
    return 0;
}
