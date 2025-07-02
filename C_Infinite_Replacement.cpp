#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n' 
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        string s, t;
        cin >> s >> t;
        n = s.size(), m = t.size();
        int freqat = 0, freqas = 0;
        for(auto e : s) freqas += (e == 'a');
        for(auto e : t) freqat += (e == 'a');
        if(freqas != 0)
        {
            if(freqat != 0)
            {
                if(t.size() == 1)
                {
                    cout << "1\n";
                }
                else
                {
                    cout << "-1\n";
                }
            }
            else
            {
                int ans = pow(2, freqas);
                cout << ans << endl;
            }
        }
        else
        {
            cout << "1\n";
        }
    }
    return 0;
}