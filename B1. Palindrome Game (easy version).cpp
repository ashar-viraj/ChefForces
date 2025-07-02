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
        string s, stemp;
        cin >> n >> s;
        stemp = s;
        reverse(s.begin(), s.end());
        if(stemp == s)
            cout << "BOB\n";
        else   
            cout << "ALICE\n";
    }
    return 0;
}