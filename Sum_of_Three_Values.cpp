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
    vector<vector<int>> v(n, vector<int>(2));
    int i = 1;
    for (auto &e : v)
    {
        cin >> e[0];
        e[1] = i++;
    }

    sort(v.begin(), v.end());
    vector<int> ans = {-1, -1, -1};

    for (int i = 0; i < n && ans[0] == -1; i++)
    {
        int req = x - v[i][0];
        if (req < 0)
            break;
        int j = i + 1, k = n - 1;
        while (j < k && ans[0] == -1)
        {
            int sum = v[j][0] + v[k][0];
            if (sum == req)
                ans = {v[i][1], v[j][1], v[k][1]};
            else if (sum < req)
                j++;
            else
                k--;
        }
    }

    sort(ans.begin(), ans.end());

    if (ans[0] == -1)
        cout << "IMPOSSIBLE";
    else
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];

    return 0;
}