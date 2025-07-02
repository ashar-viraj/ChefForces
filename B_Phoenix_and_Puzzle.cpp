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

    int t, i, j, itemp, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a = n / 2;
        itemp = sqrt(a);
        if (itemp * itemp == a && !(n%2))
        {
            cout << "YES\n";
            continue;
        }
        a = n / 4;
        itemp = sqrt(a);
        if (itemp * itemp == a && !(n%4))
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}