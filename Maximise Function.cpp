#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(i = a; i < b; i++)
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
        vector<int> v(n);
        rep(i, 0, n)
            cin >> v[i];
        sort(v.begin(), v.end());
        cout << 2*(v[n-1]-v[0]) << "\n";
    }
    return 0;
}