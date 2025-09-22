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
#define pb push_back
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    int n;
    cin >> n;

    if (n == 1)
        cout << "0";

    if (n == 2)
        cout << "0\n6";

    if (n == 3)
        cout << "0\n6\n28";

    if (n <= 3)
        return 0;

    vector<int> ans(n + 1, 0);
    ans[2] = 6;
    ans[3] = 28;

    for (int k = 4; k <= n; k++)
    {
        int invalid = 0;

        invalid += (k - 4) * 8 + 2 * 3 + 3 * 4;
        invalid -= 2;

        ans[k] = ans[k - 1] + (2 * k - 1) * ((k - 1) * (k - 1)) + ((2 * k - 1) * (2 * k - 2)) / 2 - invalid;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;

    return 0;
}