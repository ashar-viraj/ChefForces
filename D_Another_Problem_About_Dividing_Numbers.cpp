#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

bool prime[50001];
vector<int> primes;

void SieveOfEratosthenes()
{
    int n = 50000;
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
    rep(i, 2, 50001)
    {
        if (prime[i])
            primes.push_back(i);
    }
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int countnoofprimes(int n)
{
    int count = 0, temp = n, i = 0;

    for (auto e : primes)
    {
        while (temp % e == 0)
        {
            temp /= e;
            count++;
        }
        if(temp == 1)
        {
            break;
        }
    }
    if (temp > 1)
        count++;
    return count;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    SieveOfEratosthenes();
    int t, i, j, n, itemp, a, b, k;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> k;
        if (k == 1)
        {
            if (a == b)
                cout << "NO\n";
            else if (!(a % b) || !(b % a))
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }
        int count = 0;
        count += countnoofprimes(a);
        count += countnoofprimes(b);
        if (k <= count)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}