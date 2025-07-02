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
        int x;
        cin >> n >> x;
        vector<int> v(n), skipped, ans;
        int sum = 0;
        rep(i, 0, n)
        {
            cin >> v[i];
            sum += v[i];
        }
        if (sum == x)
        {
            cout << "NO\n";
            continue;
        }
        sort(v.begin(), v.end());
        sum = 0;
        rep(i, 0, n)
        {
            if (sum + v[i] == x)
            {
                skipped.push_back(v[i]);
                continue;
            }
            ans.push_back(v[i]);
            sum += v[i];
        }
        rep(i, 0, skipped.size())
        {
            ans.push_back(skipped[i]);
        }
        cout << "YES\n";
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}