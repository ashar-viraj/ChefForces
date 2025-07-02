#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define endl '\n' 
#define mp make_pair


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    string s = "", ans = "", stemp;
    bool change = true;
    while(true)
    {
        getline(cin, stemp);
        if(stemp.empty())
            break;
        s += stemp + "\n";
        stemp = "";
    }
    rep(i, 0, s.size())
    {
        if(s[i] == '"')
        {
            if(change)
            {
                ans += "``";
                change = false;
            }
            else
            {
                ans += "''";
                change = true;
            }
        }
        else
        {
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}