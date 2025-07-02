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
        vector<int> v(n);
        int ans = n, target = 0;

        rep(i, 0, n)
        {
            cin >> v[i];
        }

        for (int i = 0; i < n; i++)
        {
            target += v[i];
            bool valid = true;
            int j = 0, sum = 0, len = 0, maxLen = i + 1;
            while (j < n)
            {
                sum += v[j];
                len++;
                // cout << sum << " " << target << endl;
                if (sum > target)
                {
                    // cout << "INvalid : " << sum << ' ' << target << endl;
                    valid = false;
                    break;
                }
                if (sum == target)
                {
                    maxLen = max(maxLen, len);
                    len = 0;
                    sum = 0;
                }
                j++;
            }
            maxLen = max(maxLen, len);
            if (sum != 0 && sum != target)
                valid = false;
            if (valid)
                ans = min(ans, maxLen);
        }

        cout << ans << endl;
    }
    return 0;
}