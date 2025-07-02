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
        int mi = INT_MAX;
        vector<int> v(n);
        rep(i, 0, n)
        {
            cin >> v[i];
            mi = min(mi, v[i]);
        }
        int count = 0;
        rep(i, 0, n)
        {
            if (v[i] == mi)
                count++;
        }
        cout << n - count << endl;
    }
    return 0;
}