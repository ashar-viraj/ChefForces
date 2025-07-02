#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int q;
        cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        while (q--)
        {

            int l, r;
            cin >> l >> r;
            unordered_set<int> ans;
            ans.insert(__gcd(v[l-1], v[l]));
            for (int i = l + 1; i <= r; i++)
            {
                for (auto e : ans)
                    ans.insert(__gcd(e, v[i - 1]));
            }
            cout << *max_element(ans.begin(), ans.end()) << endl;
        }
    }
    return 0;
}