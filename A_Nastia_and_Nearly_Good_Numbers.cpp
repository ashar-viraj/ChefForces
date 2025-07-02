#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

bool prime[100001];

void SieveOfEratosthenes(int n = 100000)
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, a, b, itemp;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (b == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << a << ' ' << a * (long long)b << ' ' << a * (long long)(b + 1) << endl;
        }
    }
    return 0;
}