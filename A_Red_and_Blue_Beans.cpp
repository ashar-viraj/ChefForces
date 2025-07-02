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

    int t, i, j, n, itemp, r, b, d;
    cin >> t;
    while (t--)
    {
        cin >> r >> b >> d;
        int mi = min(r, b), ma = max(r, b);
        if(ma <= mi+mi*d)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}