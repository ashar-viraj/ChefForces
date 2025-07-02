#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        int v = k - n * m / 2;
        if (n % 2)
            if (k >= m / 2)
                if ((k - m / 2) % 2)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            else
                cout << "NO\n";
        else if (m % 2)
            if (v >= n / 2)
                if ((v - n / 2) % 2)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            else
                cout << "NO\n";
        else
        {
            if (k % 2 == 0 && (n * m / 2 - k) % 2 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}