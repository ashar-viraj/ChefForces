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

    int t, i, j, n, itemp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int sum = 0;
        rep(i, 0, n)
        {
            cin >> itemp;
            sum += itemp;
        }
        if (sum < n)
            cout << "1\n";
        else
            cout << sum - n << endl;
    }
    return 0;
}