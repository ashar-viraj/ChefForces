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

    int t, i, j, n, itemp, min, max, k, l;
    cin >> t;
    while (t--)
    {
        cin >> n >> min >> max;
        int mid, ans = 0;
        vector<int> a(n);
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        rep(i, 0, n)
        {
            ans += upper_bound(a.begin(), a.end(), max - a[i]) - a.begin();
            ans -= lower_bound(a.begin(), a.end(), min - a[i]) - a.begin();
            if (min <= 2 * a[i] && 2 * a[i] <= max)
                ans--;
        }
        cout << ans / 2 << endl;
    }
    return 0;
}