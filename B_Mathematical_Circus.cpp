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
        cin >> n >> m;
        m %= 4;
        if (m == 0)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 1; i <= n; i += 2)
        {
            if (i % 4 == 1)
            {
                if (m == 1 || m == 3)
                    cout << i << ' ' << i + 1 << endl;
                else
                    cout << i + 1 << ' ' << i << endl;
            }
            else
                cout << i << ' ' << i + 1 << endl;
        }
    }
    return 0;
}