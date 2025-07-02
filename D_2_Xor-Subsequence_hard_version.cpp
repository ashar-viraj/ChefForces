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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int g1, g2;
        g1 = __gcd(a, b);
        g2 = __gcd(c, d);
        a /= g1, b /= g1;
        c /= g2, d /= g2;

        int ans = 0;

        if (c == 0 && a == 0 || a * d == b * c)
        {
            cout << "0\n";
            continue;
        }
        if (c == 0 || a == 0)
        {
            cout << "1\n";
            continue;
        }

        if ((b * c) % (a * d) == 0)
        {
            cout << "1\n";
        }
        else if ((a * d) % (b * c) == 0)
        {
            cout << "1\n";
        }
        else
        {
            cout << "2\n";
        }
    }
    return 0;
}
/*
a c
b d
A B C D
1 1 2 3
*/