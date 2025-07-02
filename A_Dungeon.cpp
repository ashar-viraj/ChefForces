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

    int t, i, j, n, itemp, a, b, c;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        int sum = a + b + c;
        if (sum % 9)
        {
            cout << "NO\n";
            continue;
        }
        int req = sum / 9;
        if (a >= req && b >= req && c >= req)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}