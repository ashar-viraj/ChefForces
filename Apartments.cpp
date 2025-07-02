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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> app(n), flat(m);
    
    rep(i, 0, n)
    {
        cin >> app[i];
    }
    rep(i, 0, m)
    {
        cin >> flat[i];
    }
    sort(app.begin(), app.end());
    sort(flat.begin(), flat.end());

    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(app[i] - flat[j]) <= k)
        {
            ans++;
            i++;
            j++;
        }
        else if (app[i] < flat[j])
            i++;
        else
            j++;
    }

    cout << ans << endl;

    return 0;
}