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

    int t, i, j, n, itemp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n], o[n];
        rep(i, 0, n)
        {
            cin >> a[i];
            o[i] = a[i];
        }
        sort(a, a + n);
        sort(o, o + n);
        rep(i, 1, n)
        {
            a[i] = a[i] + a[i - 1];
        }
        if (a[n - 1] % n != 0)
        {
            cout << -1 << endl;
            continue;
        }
        int req2 = a[n - 1] / n, count = 0;
        for (i = 0; i < n; i++)
        {
            if (o[i] <= req2)
            {
                count++;
            }
        }
        cout << n - count << endl;
    }
    return 0;
}