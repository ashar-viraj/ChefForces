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
        int a[n + 1];
        a[0] = 0;
        rep(i, 1, n + 1)
        {
            cin >> a[i];
        }
        int count = 0;
        rep(i, 1, n + 1)
        {
            for (j = a[i] - i; j < n + 1; j += a[i])
            {
                if(j <= 0)
                {
                    continue;
                }
                if (a[i] * a[j] == i + j && i != j)
                {
                    count++;
                }
            }
        }
        cout << count/2 << endl;
    }
    return 0;
}