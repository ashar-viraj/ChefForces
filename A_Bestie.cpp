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
        vector<int> v(n + 1);
        vector<int> primes = {1, 2, 3, 5, 7, 11, 13, 17, 19};
        unordered_map<int, bool> isPrime;
        for (auto e : primes)
        {
            isPrime[e] = true;
        }
        rep(i, 1, n + 1)
        {
            cin >> v[i];
        }

        int idx = primes[primes.size() - 1];
        int i = primes.size() - 1;
        while (primes[i] >= n)
            i--;

        int g = v[0];
        for (auto e : v)
        {
            g = __gcd(g, e);
        }
        if (g == 1)
        {
            cout << "0\n";
            continue;
        }

        int ans;
        for (int i = n; i >= 1; i--)
        {
            if (isPrime[__gcd(i, v[i])])
            {
                ans = min((n - i + 1));
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}