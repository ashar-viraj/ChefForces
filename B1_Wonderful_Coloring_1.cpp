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
        string s;
        map<char, int> freq;
        cin >> s;
        int ans = 0;
        rep(i, 0, s.size())
        {
            freq[s[i]]++;
        }
        int count1 = 0;
        for(auto e : freq)
        {
            if(e.second >= 2)
            {
                ans ++;
            }
            else if(e.second == 1)
            {
                count1++;
            }
        }
        ans += count1/2;
        cout << ans << endl;
    }
    return 0;
}