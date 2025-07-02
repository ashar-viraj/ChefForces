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

    int t, i, j, n, m, itemp, k, l;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> i >> j;
        int length = 0, pathLength = 0, x1 = 1, y1 = 1, x2 = 1, y2 = 1;
        int corners[4][2] = {{1, 1}, {1, m}, {n, 1}, {n, m}};
        rep(k, 0, 3)
        {
            rep(l, k + 1, 4)
            {
                pathLength = 0;
                pathLength += abs(corners[k][0] - i) + abs(corners[k][1] - j);
                pathLength += abs(corners[l][0] - corners[k][0]) + abs(corners[l][1] - corners[k][1]);
                pathLength += abs(i - corners[l][0]) + abs(j - corners[l][1]);
                if (pathLength > length)
                {
                    length = pathLength;
                    x1 = corners[k][0];
                    y1 = corners[k][1];
                    x2 = corners[l][0];
                    y2 = corners[l][1];
                }
            }
        }
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    return 0;
}