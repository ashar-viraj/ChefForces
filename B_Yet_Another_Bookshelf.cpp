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
        int s = -1, e = 0, ans = 0;
        rep(i, 0, n)
        {
            cin >> itemp;
            v.push_back(itemp);
        }
        rep(i, 0, n)
        {
            if (v[i] == 1)
            {
                s = i;
                break;
            }
        }
        rep(i, 0, n)
        {
            if(v[i] == 1)
            {
                e = i;
            }
        }
        rep(i, s, e)
        {
            if (v[i] == 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}