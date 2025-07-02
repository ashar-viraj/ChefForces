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
        if (n == 3)
        {
            cout << "-1\n";
            continue;
        }
        if (n == 6)
        {
            cout << "5 2 1 4 3 6\n";
            continue;
        }

        vector<int> v(n + 1);
        for (int i = 1; i <= n; i += 2)
        {
            if (n % 2 && i == n)
            {
                v[i] = i;
            }
            else
            {
                v[i] = i + 1;
                v[i + 1] = i;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (v[i] == 5)
                continue;
            cout << v[i] << ' ';
        }
        if (n > 4)
            cout << 5;
        cout << endl;
    }
    return 0;
}