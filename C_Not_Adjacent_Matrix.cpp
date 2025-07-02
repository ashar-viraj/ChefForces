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

    int t, i, j, n, itemp, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n][n];
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        else if (n == 2)
        {
            cout << -1 << endl;
            continue;
        }
        int value = 1;
        for (k = n - 2; k >= 0; k--)
        {
            i = k;
            j = 0;
            while (i < n)
            {
                a[i++][j++] = value++;
            }
        }
        for (k = 1; k <= n - 2; k++)
        {
            i = 0;
            j = k;
            while (j < n)
            {
                a[i++][j++] = value++;
            }
        }
        a[n - 1][0] = value++;
        a[0][n - 1] = value;
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}