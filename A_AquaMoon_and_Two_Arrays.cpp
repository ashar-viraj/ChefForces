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
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n),b(n);
        int sa = 0, sb = 0;
        rep(i, 0, n)
        {
            cin >> a[i];
            sa+=a[i];
        }
        rep(i, 0, n)
        {
            cin >> b[i];
            sb+=b[i];
        }
        if(sa != sb)
        {
            cout << "-1\n";
            continue;
        }
        vector<int> inc, dec, ansinc, ansdec;
        rep(i, 0, n)
        {
            if(a[i] < b[i])
                inc.push_back(i);
            else if(a[i] > b[i])
                dec.push_back(i);
        }
        rep(i, 0, inc.size())
        {
            int x = abs(a[inc[i]] - b[inc[i]]);
            rep(j, 0, x)
            {
                ansinc.push_back(inc[i]+1);
            }
        }
        rep(i, 0, dec.size())
        {
            int x = abs(a[dec[i]] - b[dec[i]]);
            rep(j, 0, x)
            {
                ansdec.push_back(dec[i]+1);
            }
        }
        cout << ansinc.size() << endl;
        rep(i, 0, ansinc.size())
        {
            cout << ansdec[i] << " " << ansinc[i] << endl;
        }
    }
    return 0;
}