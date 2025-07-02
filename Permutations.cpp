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
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    int val = n, i = 0, ans[n];
    if (n % 2 == 0)
        val--;
    while (val >= 1)
    {
        ans[i] = val;
        i++;
        val -= 2;
    }

    val = n;
    if (n % 2)
        val--;
    while (i < n)
    {
        ans[i] = val;
        i++;
        val -= 2;
    }

    rep(i, 0, n)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}