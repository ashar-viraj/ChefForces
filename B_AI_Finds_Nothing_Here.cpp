#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 998244353
#define f first
#define s second
#define pb push_back

long long modpow(long long base, long long exp, long long mod){
    base %= mod;
    if (base < 0) base += mod;
    long long result = 1;
    while(exp > 0){
        if (exp & 1LL) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;

        long long term1 = n * m;                      // up to 1e18, fits in int64
        long long term2 = (n - r + 1) * (m - c + 1);   // <= term1 always
        long long E = term1 - term2;                   // exponent, always >= 0
        long long e = E % (MOD - 1);                    // Fermat's little theorem reduction
        cout << modpow(2, e, MOD) << endl;
    }
    return 0;
}