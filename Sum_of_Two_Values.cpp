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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0];
        v[i][1] = i + 1;
    }

    sort(v.begin(), v.end());

    int i = 0, j = n - 1;
    pair<int, int> ans = {-1, -1};

    while (i < j && ans.f == -1)
    {
        int sum = v[i][0] + v[j][0];
        if (sum == k)
            ans = {v[i][1], v[j][1]};
        else if (sum < k)
            i++;
        else
            j--;
    }

    if (ans.f > ans.s)
        swap(ans.f, ans.s);

    if (ans.f == -1)
        cout << "IMPOSSIBLE";
    else
        cout << ans.f << ' ' << ans.s;

    return 0;
}