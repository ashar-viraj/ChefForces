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

    

    int t, i, j, n, itemp, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<string> v(2*n-1);
        rep(i ,0, 2*n-1)
        {
            cin >> v[i];
        }
        cout << flush;
        map<int, map<char, int>> cf;//char freq
        string ans = "";
        rep(i, 0, 2*n-1)
        {
            rep(j, 0, m)
            {
                cf[j][v[i][j]]++;
                // cout << v[i][j];
            }
            // cout << endl;
        }
        rep(i, 0, m)
        {
            for(auto itr = 'a'; itr <= 'z'; itr++)
            {
                if(cf[i][itr]%2)
                {
                    ans += itr;
                }
            }
        }
        cout << ans << "\n" << flush;
    }
    return 0;
}