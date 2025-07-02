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
        vector<int> v(n), ans;
        rep(i, 0, n)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int mindiff = v[1] - v[0], s = 0, e = 1;
        rep(i, 2, n)
        {
            if(v[i] - v[i-1] < mindiff)
            {
                mindiff = v[i] - v[i-1];
                s = i-1;
                e = i;
            }
        }
        cout << v[s] << " ";
        rep(i, e+1, n)
            cout << v[i] << " ";
        rep(i, 0, s)
            cout << v[i] << " ";
        cout << v[e] << endl;
    }
    return 0;
}
        // ans.push_back(v[s]);
        // rep(i, e+1, n)
        // {
        //     ans.push_back(v[i]);
        // }
        // rep(i, 0, s)
        // {
        //     ans.push_back(v[i]);
        // }
        // ans.push_back(v[e]);