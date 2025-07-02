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

class rod
{
public:
    int a, b;
};

bool compare(rod &a, rod &b)
{
    if (a.a != b.a)
        return a.a < b.a;
    return a.b < b.b;
}

int solve(vector<rod> &rods, int i, int j, int start, int chance)
{
    int ans = 0;

    int times = rods.size();

    while (times--)
    {
        if (chance == 0)
        {
            if (i >= 0)
            {
                ans += rods[i].b * start;
                start += rods[i].a;
                i--;
            }
        }
        else
        {
            ans += rods[j].b * start;
            start += rods[j].a;
            j--;
        }
        chance ^= 1;
    }

    return ans;
}

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
        vector<rod> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].a;

        for (int i = 0; i < n; i++)
            cin >> v[i].b;

        sort(v.begin(), v.end(), compare);

        if (n % 2)
        {
            int ans1 = solve(v, n / 2, n - 1, 0, 0), ans2 = solve(v, n / 2 - 1, n - 1, 0, 0);

            cout << max(ans1, ans2) << endl;
        }
        else
        {
            cout << solve(v, n / 2 - 1, n - 1, 0, 0) << endl;
        }
    }
    return 0;
}