/*
0 1 2 3 4
2 1 5 4 3

1 0 4 3 2
*/

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
    vector<vector<int>> v(n, vector<int>(2));
    rep(i, 0, n)
    {
        cin >> v[i][0];
        v[i][1] = i;
    }

    sort(v.begin(), v.end());

    int ans = 1, i = n - 2;
    while (i >= 0)
    {
        if (v[i][1] > v[i + 1][1])
            ans++;
        i--;
    }

    cout << ans;

    return 0;
}