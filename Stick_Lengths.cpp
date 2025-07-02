#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
#define f first
#define s second
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n), prefix(n, 0), suffix(n, 0);

    rep(i, 0, n)
    {
        cin >> v[i];
    }
    int total = 0;
    sort(v.begin(), v.end());
    rep(i, 0, n)
    {
        prefix[i] = total;
        total += v[i];
    }
    total = 0;
    reprev(i, n - 1, 0)
    {
        suffix[i] = total;
        total += v[i];
    }

    int ans = LONG_MAX;
    rep(i, 0, n)
    {
        int cost = (i * v[i] - prefix[i]) + (suffix[i] - (n - i - 1) * v[i]);
        ans = min(ans, cost);
    }

    cout << ans;

    return 0;
}
