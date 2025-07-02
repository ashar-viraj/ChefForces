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
        vector<int> even, odd;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> itemp;
            if (itemp % 2)
            {
                odd.push_back(itemp);
            }
            else
            {
                even.push_back(itemp);
            }
        }
        if (odd.size() >= even.size())
        {
            cout << odd.size() - n << endl;
        }
        else
        {
            vector<int> req;
            for (int i = 0; i < even.size(); i++)
            {
                int val = even[i], op = 0;
                while ((val % 2) == 0)
                {
                    op++;
                    val /= 2;
                }
                req.push_back(op);
            }
            sort(req.begin(), req.end());
            int range = even.size() - n;
            i = 0;
            int ans = 0;
            while (range--)
            {
                ans += req[i];
                i++;
            }
            cout << ans << endl;
        }
    }

    return 0;
}