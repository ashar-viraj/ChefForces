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
        map<int, int> freq;
        int ans = INT_MAX, req;
        cin >> itemp;
        v.push_back(itemp);
        rep(i, 1, n)
        {
            cin >> itemp;
            if (v[v.size() - 1] != itemp)
                v.push_back(itemp);
        }
        for (auto e : v)
            freq[e]++;
        for (auto e : freq)
        {
            ans = min(ans, (e.second + 1) - (v[0] == e.first) - (v[v.size() - 1] == e.first));
        }
        cout << ans << endl;
    }
    return 0;
}