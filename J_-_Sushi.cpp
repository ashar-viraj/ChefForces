#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define vr vector
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
#define f first
#define s second
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

double solve(int one, int two, int three, int n, vr<vr<vr<double>>> &dp)
{
    if (one + two + three == 0)
        return 0;

    if (dp[one][two][three] != -1)
        return dp[one][two][three];

    double ans = 1,
           p1 = (double)one / n,
           p2 = (double)two / n,
           p3 = (double)three / n;
    if (three > 0)
        ans += p3 * solve(one, two + 1, three - 1, n, dp);
    if (two > 0)
        ans += p2 * solve(one + 1, two - 1, three, n, dp);
    if (one > 0)
        ans += p1 * solve(one - 1, two, three, n, dp);

    ans /= (p1 + p2 + p3);

    return dp[one][two][three] = ans;
}

int32_t main()
{
    int n;
    cin >> n;
    vr<vr<vr<double>>> dp(n + 1, vr<vr<double>>(n + 1, vr<double>(n + 1, -1)));

    vr<int> v(n);
    int count[4] = {0};
    for (auto &e : v)
    {
        cin >> e;
        count[e]++;
    }

    double ans = solve(count[1], count[2], count[3], n, dp);

    cout << setprecision(10) << fixed << ans << endl;

    return 0;
}