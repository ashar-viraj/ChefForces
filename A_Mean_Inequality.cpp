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
        vector<int> v(2*n);
        rep(i, 0, 2 * n)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        rep(i, 0, n)
        {
            ans.push_back(v[i]);
            ans.push_back(v[i + n]);
        }
        rep(i, 1, 2 * n)
        {
            if (ans[i] == (ans[i - 1] + ans[(i + 1) % (2 * n)]) / 2)
            {
                swap(ans[i], ans[(i + 1) % (2 * n)]);
            }
        }
        rep(i, 0, 2*n)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}