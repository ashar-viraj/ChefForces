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
            cin >> a[i];
        sort(a, a + n);
        int posMinIdx = -1, notPositiveCount = 0, diff = __INT_MAX__;
        rep(i, 0, n)
        {
            if (a[i] <= 0)
            {
                if (a[i + 1] < 1)
                    if (abs(a[i] - a[i + 1]) < diff)
                        diff = abs(a[i] - a[i + 1]);
                notPositiveCount++;
            }
            else
            {
                posMinIdx = i;
                break;
            }
        }
        if(posMinIdx == -1)
            cout << notPositiveCount << endl;
        else if(diff >= a[posMinIdx])
            cout << notPositiveCount + 1 << endl;
        else
            cout << notPositiveCount << endl;
    }
    return 0;
}