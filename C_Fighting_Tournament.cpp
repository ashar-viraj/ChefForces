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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<int> winStart(n + 1, -1), winEnd(n + 1, -1);

        int ma = v[0];
        if (v[0] > v[1])
            winStart[ma - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i] > ma)
            {
                winStart[v[i] - 1] = i;
                winEnd[ma - 1] = i - 1;
                ma = v[i];
            }
        }
        winEnd[ma - 1] = INT_MAX;

        while (m--)
        {
            int a, b;
            cin >> a >> b;
            if (winStart[v[a - 1] - 1] == -1)
                cout << "0\n";
            else
                cout << max((int)0, min(b, winEnd[v[a - 1] - 1]) - winStart[v[a - 1] - 1] + 1) << endl;
        }
    }
    return 0;
}