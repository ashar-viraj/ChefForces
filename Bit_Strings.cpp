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

int solve(int n)
{
    if (n == 0)
        return 1;
    int ans = solve(n / 2);
    if (n % 2)
        ans = (ans * ans * 2) % MOD;
    else
        ans = (ans * ans) % MOD;
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}