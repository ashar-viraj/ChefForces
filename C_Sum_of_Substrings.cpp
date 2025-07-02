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
        int k;
        string s;
        cin >> n >> k;
        cin >> s;
        int ans = 0;

        vector<int> idx;

        int firstone = -1, lastone = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                continue;
            if (i == 0)
                ans += 10;
            else if (i == n - 1)
                ans += 1;
            else
                ans += 11;
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                firstone = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                lastone = i;
                break;
            }
        }

        if (firstone == -1)
        {
            cout << "0\n";
        }
        else if (s[0] == '1' && s[n - 1] == '1')
        {
            cout << ans << endl;
        }
        else if (s[0] == '1')
        {
            if ((lastone == firstone) && (n - (lastone + 1) <= k))
            {
                ans++;
                ans -= 10;
            }
            else if (n - (lastone + 1) <= k)
            {
                ans -= 10;
            }
            cout << ans << endl;
        }
        else if (s[n - 1] == '1')
        {
            if ((firstone != lastone) && (firstone <= k))
                ans -= 1;
            cout << ans << endl;
        }
        else
        {
            if (lastone == firstone)
            {
                if (n - (lastone + 1) <= k)
                    ans -= 10;
                else if (firstone <= k)
                    ans -= 1;
                cout << ans << endl;
            }
            else
            {
                if (n - (lastone + 1) <= k)
                {
                    ans -= 10;
                    k = k - (n - (lastone + 1));
                }
                if (firstone <= k)
                {
                    ans -= 1;
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}