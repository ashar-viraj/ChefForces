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
        cin >> n;
        vector<int> v(n);
        vector<vector<int>> pos(n + 1);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            pos[v[i]].push_back(i);
        }
        unordered_map<int, int> lastOdd, lastEven, maxLen, oddLen, evenLen;

        for (int i = 1; i <= n; i++)
        {
            lastOdd[i] = -1;
            lastEven[i] = -1;
            maxLen[i] = 0, oddLen[i] = 0, evenLen[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (auto idx : pos[i])
            {
                if (idx % 2)
                    oddLen[i] = evenLen[i] + 1;
                else
                    evenLen[i] = oddLen[i] + 1;
                maxLen[i] = max({maxLen[i], evenLen[i], oddLen[i]});
            }
        }

        for (int i = 1; i <= n; i++)
            cout << maxLen[i] << ' ';
        cout << endl;
    }
    return 0;
}