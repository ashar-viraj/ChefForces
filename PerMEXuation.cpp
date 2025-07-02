#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        string s;
        cin >> n >> s;
        if (s.size() == 2)
        {
            if (s[0] == '0' || s[1] == '1')
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
                cout << "0 1\n";
            }
        }
        else
        {
            int ans[n + 1];
            if (s[0] == '0' || s[1] == '0' || s[n] == '0')
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
                vector<int> zeroes, ones;
                for (int i = 0; i <= n; i++)
                {
                    if (s[i] == '0')
                        zeroes.push_back(i);
                    else
                        ones.push_back(i);
                }
                i = 0, j = 0;
                cout << ones[0] << ' ';
                for (int i = 0; i < zeroes.size(); i++)
                    cout << zeroes[i] << ' ';
                for (int i = 1; i < ones.size() - 1; i++)
                    cout << ones[i] << ' ';
                cout << endl;
            }
        }
    }
    return 0;
}