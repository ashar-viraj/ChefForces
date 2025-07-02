#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define mod (1000000000 + 7)

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
        int ans = 0, lcm = 1;
        for (i = 1; i <= n; i++)
        {
            lcm = (lcm * i) / __gcd(lcm, i);
            if (lcm > n)
                break;
            ans += n / lcm;
        }
        cout << (ans + n) % mod << endl;
    }
    return 0;
}