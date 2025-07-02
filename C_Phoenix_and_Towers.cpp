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

    int t, i, j, n, itemp, m, x;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m >> x;
        vector<int> v(n);
        rep(i, 0, n)
        {
            cin >> v[i];
        }
        set<pair<int, int>> s;
        rep(i, 1, m + 1)
        {
            s.insert({0,i});
        }
        cout << "YES\n";
        rep(i, 0, n)
        {
            auto p = *s.begin();
            cout << p.second << " ";
            s.insert({p.first + v[i], p.second});
            s.erase(p);
        }
        cout << "\n";
    }
    return 0;
}