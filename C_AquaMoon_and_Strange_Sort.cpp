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
        vector<int> v(n + 1), a(n + 1);
        v[0] = 0;
        a[0] = 0;
        rep(i, 1, n + 1)
        {
            cin >> v[i];
            a[i] = v[i];
        }
        sort(a.begin(), a.end());
        map<int, pair<int, int>> oddeven, oldoddeven;
        rep(i, 1, n + 1)
        {
            if (i % 2)
            {
                oldoddeven[v[i]].first++;
                oddeven[a[i]].first++;
            }
            else
            {
                oldoddeven[v[i]].second++;
                oddeven[a[i]].second++;
            }
        }
        bool valid = true;
        for (auto itr = oldoddeven.begin(); itr != oldoddeven.end(); itr++)
        {
            if (oldoddeven[itr->first].second == oddeven[itr->first].second && oldoddeven[itr->first].first == oddeven[itr->first].first)
            {
                continue;
            }
            valid = false;
        }
        if(valid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}