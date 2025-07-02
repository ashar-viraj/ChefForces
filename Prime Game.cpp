#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

vector<bool> prime(10000001);
vector<int> primeCount(1000001);

void SieveOfEratosthenes(int n)
{

    for (int i = 0; i < 1000001; i++)
    {
        prime[i] = true;
    }

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    primeCount[0] = 0;
    primeCount[1] = 0;
    primeCount[2] = 1;
    for (int i = 3; i < 1000001; i++)
    {
        if (prime[i])
        {
            primeCount[i] = primeCount[i - 1] + 1;
        }
        else
        {
            primeCount[i] = primeCount[i - 1];
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    SieveOfEratosthenes(1000001);

    int t, i, j, x, itemp, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        if (primeCount[x] > y)
            cout << "Divyam\n";
        else
        {
            cout << "Chef\n";
        }
    }
    return 0;
}