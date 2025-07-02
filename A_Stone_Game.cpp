#include <bits/stdc++.h>
#include <algorithm>
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
        int min = INT_MAX, max = INT_MIN, minidx = 0, maxidx = 0;
        rep(i, 0, n)
        {
            cin >> itemp;
            if (itemp > max)
            {
                maxidx = i;
                max = itemp;
            }
            if (itemp < min)
            {
                minidx = i;
                min = itemp;
            }
        }
        i = minidx < maxidx ? minidx : maxidx;
        j = minidx > maxidx ? minidx : maxidx;
        i++;
        j++;
        int a = n - i + 1, b = j, c = n - j + i + 1;
        int ans = a < b ? a : b;
        ans = ans < c ? ans : c;
        cout << ans << endl;
    }
    return 0;
}