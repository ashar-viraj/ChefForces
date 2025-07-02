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

    int t, i, j, n, m, itemp;
    cin >> n;
    vector<int> v(n), ans(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    ans[0] = 0;
    ans[1] = abs(v[1] - v[0]);
    
    for (int i = 2; i < n; i++)
        ans[i] = min(ans[i - 1] + abs(v[i] - v[i - 1]), ans[i - 2] + abs(v[i] - v[i - 2]));

    cout << ans[n - 1] << endl;

    return 0;
}
/*
0 0 10 
*/