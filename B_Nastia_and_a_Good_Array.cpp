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
        vector<int> v;
        int min = INT_MAX, minid = 0;
        rep(i, 0, n)
        {
            cin >> itemp, v.push_back(itemp), itemp < min ? (min = itemp, minid = i) : min = min;
        }
        cout << n - 1 << endl;
        int y = min + 1;
        rep(i, minid + 1, n)
        {
            cout << minid + 1 << " " << i + 1 << " " << min << " " << y++ << endl;
        }
        y = min + 1;
        for (i = minid - 1; i >= 0; i--)
        {
            cout << minid + 1 << " " << i + 1 << " " << min << " " << y++ << endl;
        }
    }
    return 0;
}