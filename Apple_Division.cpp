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

void solve(vector<int> &v, int i, int n, int s1, int s2, int &ans)
{
    if (i == n)
    {
        ans = min(ans, abs(s1 - s2));
        return;
    }

    solve(v, i + 1, n, s1 + v[i], s2, ans);
    solve(v, i + 1, n, s1, s2 + v[i], ans);
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, 0, n)
            cin >>
        v[i];

    int ans = INT_MAX;
    solve(v, 0, n, 0, 0, ans);
    cout << ans;

    return 0;
}