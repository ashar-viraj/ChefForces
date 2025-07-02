#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define f first
#define s second
#define MOD 998244353
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int power(int x, int y, int p)
{
    int res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int n, int p)
{
    return power(n, p - 2, p);
}

int nCrModPFermat(int n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    vector<vector<int>> v(1001, vector<int>(1001, 1));
    vector<int> power2(1000002, 1);
    for (int i = 1; i < 1000002; i++)
    {
        power2[i] = (power2[i - 1] * 2ll) % MOD;
    }
    for (int i = 999; i >= 0; i--)
        for (int j = 999; j >= 0; j--)
            v[i][j] = (v[i + 1][j] + v[i][j + 1]) % MOD;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        if ((n + m) % 2)
        {
            int len = n + m - 1;
            int ans = nCrModPFermat(len, len / 2, MOD);
            // cout << ans << ' ';
            ans = (((ans * v[1001 - n][1001 - m]) % MOD) * power2[n * m - len]) % MOD;
            cout << ans << endl;
        }
        else
        {
            cout << "0\n";
        }
    }
    return 0;
}