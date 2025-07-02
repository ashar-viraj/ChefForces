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
        int ans = 0, req;
        string s, stemp;
        cin >> s;
        ans += (s.size() - 1) * 9;
        stemp = s;
        rep(i, 1, s.size())
        {
            s[i] = s[0];
        }
        req = stoi(s);
        if (stoi(stemp) - req >= 0)
            ans += stemp[0] - '0';
        else
            ans += (stemp[0] - '0') - 1;
        cout << ans << endl;
    }
    return 0;
}