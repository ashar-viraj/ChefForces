#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
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
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        vector<int> ans(3);
        if (n % 2 && m % 2)
        {
            ans[0] = 2;
            ans[1] = n ^ 2;
            ans[2] = m ^ 2;
        }
        else
        {
            ans[0] = 2;
            if(n%2)
            {
                ans[1] = (n ^ 2);
                ans[2] = ans[1] ^ m;
            }
            else
            {
                ans[1] = (m^2);
                ans[2] = (n^ans[1]);
            }
        }
        sort(ans.begin(), ans.end());
        for (auto e : ans)
            cout << e << ' ';
        cout << endl;
    }
    return 0;
}