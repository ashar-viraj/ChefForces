#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n' 
#define mp make_pair
#define f first
#define s second
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
    unordered_map<char, bool> vow;
    vow['a'] = true;
    vow['e'] = true;
    vow['i'] = true;
    vow['o'] = true;
    vow['u'] = true;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        string s;
        cin >> s;
        int ans = 0, len = 0;
        for(int i = 0; i < n; i++)
        {
            if(vow[s[i]])
            {
                len = 0;
            }
            else
            {
                len++;
            }
            ans = max(len , ans);
        }
        out((ans < 4));
    }
    return 0;
}