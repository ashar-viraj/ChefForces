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
        int a[n];
        rep(i, 0, n)
                cin >>
            a[i];
        int Ugniless = a[0] + a[n - 1], finalUgliness = 0;
        if (n == 1)
        {
            cout << a[0] << endl;
            continue;
        }
        rep(i, 0, n - 1) 
            if (a[i] > a[i + 1])
                Ugniless += a[i] - a[i + 1];

        rep(i, 1, n) 
            if (a[i] > a[i - 1])
                Ugniless += a[i] - a[i - 1];

        rep(i, 0, n)
        {
            if (i == 0 && a[0] > a[1])
            {
                Ugniless -= abs(a[0] - a[1]);
                continue;
            }
            if (i == n - 1 && a[n - 1] > a[n - 2])
            {
                Ugniless -= abs(a[n - 1] - a[n - 2]);
                continue;
            }
            if (a[i] > a[i + 1] && a[i] > a[i - 1])
            {
                Ugniless -= abs(a[i] - max(a[i - 1], a[i + 1]));
            }
        }
        cout << Ugniless << endl;
    }
    return 0;
}