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

    int t, i, j, n, itemp, k, m;
    cin >> t;
    while (t--)
    {
        cin >> k >> n >> m;
        int a[n], b[m];
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        rep(i, 0, m)
        {
            cin >> b[i];
        }
        int x = 0, y = 0;
        vector<int> ans;
        bool found = true;
        while (true)
        {
            if (x >= n && y >= m)
                break;
            if (x < n && a[x] == 0)
            {
                ans.push_back(a[x++]);
                k++;
            }   
            else if (y < m && b[y] == 0)
            {
                ans.push_back(b[y++]);
                k++;
            }
            else if (x < n && a[x] <= k)
                ans.push_back(a[x++]);
            else if (y < m && b[y] <= k)
                ans.push_back(b[y++]);
            else
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            rep(i, 0, n + m)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        else
            cout << "-1\n";
    }
    return 0;
}