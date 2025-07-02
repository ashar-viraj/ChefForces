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
        string s;
        cin >> s;
        vector<int> pre(n, 0);
        pre[0] = s[0] - '0';
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + (s[i] - '0');

        int onecount = 0;
        for (int i = 0; i < n; i++)
            onecount += (s[i] - '0');

        if (onecount == 0)
        {
            cout << n * m << endl;
            continue;
        }
        if (onecount == n)
        {
            if (n * m % 2 == 0)
                cout << "1\n";
            else
                cout << "0\n";
            continue;
        }

        int ans = 0;

        if (m % 2)
        {
            for (int i = 0; i < n; i++)
            {
                if (pre[i] == onecount - pre[i])
                {
                    ans++;
                }
            }
        }
        else
        {
            int i = 0;
            while(s[i] == '0')
            {
                i++;
                ans++;
            }
            i = n-1;
            while(s[i] == '0')
            {
                i--;
                ans++;
            }
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}