#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

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
        unordered_map<int, int> m;
        rep(i, 0, n)
        {
            cin >> itemp;
            m[itemp]++;
        }
        bool done = false;
        for (auto e : m)
        {
            if (e.second >= 3)
            {
                cout << e.first << endl;
                done = true;
                break;
            }
        }
        if (!done)
        {
            cout << "-1\n";
        }
    }
    return 0;
}