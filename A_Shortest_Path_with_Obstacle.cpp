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

    int t, i, j, n, itemp, xa, xb, xc, xf, ya, yb, yf;
    cin >> t;
    while (t--)
    {
        cin >> xa >> ya;
        cin >> xb >> yb;
        cin >> xf >> yf;
        int moves = 0;
        if (xa == xb && xb == xf)
        {
            if ((ya < yf && yf < yb) || yb < yf && yf < ya)
                moves += 2;
        }
        if (ya == yb && yb == yf)
        {
            if ((xa < xf && xf < xb) || (xb < xf && xf < xa))
                moves += 2;
        }
        moves += abs(xa - xb) + abs(ya - yb);
        cout << moves << endl;
    }
    return 0;
}