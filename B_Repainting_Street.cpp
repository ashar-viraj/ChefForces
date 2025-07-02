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
        int k;
        cin >> n >> k;
        unordered_map<int, vector<int>> idx;
        for (int i = 1; i <= n; i++)
        {
            int col;
            cin >> col;
            idx[col].push_back(i);
        }

        int ans = n;

        for (auto e : idx)
        {
            int lastColored = 0, smallAns = 0;
            vector<int> v = e.second;
            m = v.size();
            i = 0;
            while (i < m && v[i] == i + 1)
                i++;
            lastColored = i;
            cout << e.first << ' ' << i << endl;
            cout << "lastColored : " << lastColored << endl;
            while (i < m)
            {
                while (i < m && v[i] <= lastColored)
                    i++;
                if (i == m)
                {
                    lastColored = max(lastColored, v[m - 1]);
                    break;
                }
                int houseRem = v[i] - lastColored;
                int houseColored = (houseRem / k) * k + k * (houseRem % k != 0);
                smallAns += houseColored / k;
                lastColored += houseColored;
                i++;
            }
            // while (i < m && v[i] == e.first)
            // {
            //     i++;
            //     lastColored
            // }
            cout << "lastColored : " << lastColored << endl
                 << endl;
            if (lastColored < n)
            {
                int houseRem = n - lastColored;
                int houseColored = (houseRem / k) * k + k * (houseRem % k != 0);
                smallAns += houseColored / k;
                lastColored += houseColored;
            }

            ans = min(ans, smallAns);
        }

        cout << ans << endl;
    }
    return 0;
}
/*
- 1 1  2  3 3  4  5 5
+ 0 1  1  1 2  2  2 3
  - +  -  - +  -  - +
 -1 0 -1 -1 0 -1 -2 -1
*/