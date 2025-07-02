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

    int t, i, j, n, itemp, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> v(n);
        rep(i, 0, n)
        {
            cin >> v[i];
        }
        int l = 0, r = n - 1;
        while (l != r && k--)
        {
            while (v[l] == 0 && l < n - 1)
                l++;
            v[n - 1]++;
            v[l]--;
        }
        rep(i, 0, n)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}