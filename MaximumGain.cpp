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
        cin >> n;
        vector<string> v(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int count[2] = {0};
                /*
                7
                1 2
                2 5
                5 4
                4 1
                */
                count[v[i][j] - '0']++;
                count[v[j][n - i - 1] - '0']++;
                count[v[n - i - 1][n - j - 1] - '0']++;
                count[v[n - j - 1][i] - '0']++;

                // cout << v[i][j] << ' ' << v[j][n - i - 1] << ' ' << v[n - i - 1][n - j - 1] << ' ' << v[n - j - 1][i] << endl;

                ans += min(count[0], count[1]);
            }
        }

        if (n % 2)
        {
            j = n / 2;
            for (int i = 0; i < n / 2; i++)
            {
                int count[2] = {0};
                count[v[i][j] - '0']++;
                count[v[j][n - i - 1] - '0']++;
                count[v[n - i - 1][n - j - 1] - '0']++;
                count[v[n - j - 1][i] - '0']++;

                // cout << v[i][j] << ' ' << v[j][n - i - 1] << ' ' << v[n - i - 1][n - j - 1] << ' ' << v[n - j - 1][i] << endl;
                ans += min(count[0], count[1]);
            }
        }

        cout << ans << endl;
        // continue;
    }
    return 0;
}
/*
n - (N-I-1) - 1
+i+1+1
*/