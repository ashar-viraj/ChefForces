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
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int ans = 0, i = 0, j = n - 1;
    while (i <= j)
    {
        if(i < j && (v[i] + v[j]) <= x)
            i++;
        j--;
        ans++;
    }

    cout << ans;

    return 0;
}