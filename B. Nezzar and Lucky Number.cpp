#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(i = a; i < b; i++)
#define mp make_pair

bool islucky(int c, int d)
{
    for(int i = 1; i < 100; i++)
    {
        if(d*i > c)
        {
            break;
        }
        string s = to_string(c-(d*i));
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == d + 48)
            {
                return true;
            }
        }
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, temp, a, b, c, d;
    cin >> t;
    while (t--)
    {
        cin >> n >> d;
        vector<int> v(n);
        rep(i, 0, n)
        {
            cin >> v[i];
        }
        rep(i, 0, n)
        {
            if(v[i] >= 100)
            {
                cout << "YES\n";
            }
            else
            {
                if(v[i] % 10 == d || (v[i]/10) == d)
                {
                    cout << "YES\n";
                }
                else if(islucky(v[i], d))
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}