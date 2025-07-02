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

int findMax(vector<int> a, int n)
{
    n = a.size();
    int ans = a[0], sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ans = max(ans, sum);
        sum = max(sum, 0ll);
    }
    return ans;
}

int solve(vector<int> a, int val, int n, int append)
{
    if (append)
    {
        a.push_back(val);
    }
    else
    {
        reverse(a.begin(), a.end());
        a.push_back(val);
    }
    return findMax(a, n);
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> m;
        vector<int> b(m);
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            if (b[i] > 0)
                sum += b[i];
        }

        int temp = 0;
        int ans = solve(a, sum, n, 0);
        ans = max(ans, solve(a, sum, n, 1));

        cout << ans << endl;
    }
    return 0;
}