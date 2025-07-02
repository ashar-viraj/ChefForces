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

    int t, i, j, n, m, itemp, k;
    cin >> n >> k;
    vector<int> v(n), ans(n);

    rep(i, 0, n)
    {
        cin >> v[i];
    }

    ans[0] = 0;
    for (int i = 0; i < min(k + 1, n); i++)
        ans[i] = abs(v[i] - v[0]);

    for (int i = k + 1; i < n; i++)
    {
        int smallAns = INT_MAX;
        int K = k;
        for (int j = i - 1; (j >= 0) && (K > 0); j--, K--)
            smallAns = min(smallAns, ans[j] + abs(v[i] - v[j]));
        // cout << endl;

        ans[i] = smallAns;
    }
    // for (int i = 0; i < n; i++)
    //     cout << ans[i] << ' ';
    // cout << endl;

    cout << ans[n - 1] << endl;

    return 0;
}