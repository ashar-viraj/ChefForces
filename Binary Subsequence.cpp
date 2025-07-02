#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (i = a; i < b; i++)
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, temp, a, b, c, d;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        string stemp;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
            {
                s = s.substr(i, n-i);
                break;
            }
        }
        if(s.size() == 1)
        {
            cout << "0\n";
            continue;
        }
        // cout << s << "\n";
        for(i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                stemp = s.substr(0, i+1);
                break;
            }
        }
        s = stemp;
        if(s.size() == 0)
        {
            cout << "0\n";
            continue;
        }
        // cout  << s << "\n";
        int r0[s.size()], l1[s.size()];
        l1[0] = 0;
        r0[s.size() - 1] = 0;
        rep(i, 1, s.size())
        {
            if (s[i - 1] == '1')
            {
                l1[i] = l1[i - 1] + 1;
            }
            else
            {
                l1[i] = l1[i - 1];
            }
        }
        for (i = s.size() - 2; i >= 0; i--)
        {
            if (s[i + 1] == '0')
            {
                r0[i] = r0[i + 1] + 1;
            }
            else
            {
                r0[i] = r0[i + 1];
            }
        }
        // rep(i, 0, s.size())
        // {
        //     cout << l1[i] << " ";
        // }
        // cout << "\n";
        // rep(i, 0, s.size())
        // {
        //     cout << r0[i] << " ";
        // }
        int operation = INT_MAX;
        rep(i, 0, s.size())
        {
            if (l1[i] + r0[i] < operation)
            {
                operation = l1[i] + r0[i];
            }
        }
        cout << operation << "\n";
    }
    return 0;
}