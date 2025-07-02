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
        string s;
        cin >> n >> s;
        bool arrived[100] = {false}, valid = true;
        rep(i, 0, n)
        {
            if (arrived[s[i]])
            {
                if (s[i] != s[i - 1])
                {
                    valid = false;
                    break;
                }
            }
            arrived[s[i]] = true;
        }
        if(valid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}