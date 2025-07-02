#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n' 
#define mp make_pair
#define f first
#define s second
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int MOD = 1e+16;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        n = 0;
        vector<int> v;
        vector<int> least(n, 0), mostup(n, 0), mostDown(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
                continue;

            least[v[i] - 1] += 1;
        }

        for (int i = n - 2; i >= 0; i--)
            least[i] += least[i + 1];

        for (int i = 0; i < n; i++)
        {
            int atmost = (n - v[i]) + 1;
            if (v[i] - 1 >= 0)
                mostup[v[i] - 1] += atmost;
            if (v[i] + 1 < n)
                mostDown[v[i] + 1] += (n - v[i]);
        }
        for (int i = 1; i < n; i++)
            mostDown[i] += mostDown[i - 1];
        for (int i = n - 2; i >= 0; i--)
            mostup[i] += mostup[i + 1];


        int k;
        cin >> n >> k;
        int temp = n;
        int ans = 1;
        while(temp--)
        {
            ans = (ans*4) % MOD;
        }
        int requiredToTemove = (1 << n)*3 - 3;
        ans = (ans - requiredToTemove) % MOD;
        ans = (ans - 1) % MOD;
        cout << ans << endl;
    }
    return 0;
}