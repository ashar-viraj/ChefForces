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
        string s, ans = "";
        cin >> n >> s;
        rep(i, 0, n)
        {
            ans += s[n-1];
        }
        cout << ans << endl;
    }
    return 0;
}