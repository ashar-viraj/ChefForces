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

bool compare(int a, int b)
{
    return a % 2 < b % 2;
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
        int a[n], count = 0;
        rep(i, 0, n)
                cin >>
            a[i];
        sort(a, a + n, compare);
        rep(i, 0, n - 1)
        {
            if (a[i] % 2 == 0)
            {
                count += (n - (i + 1));
                continue;
            }

            rep(j, i + 1, n) if (gcd(a[i], 2 * a[j]) != 1)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}