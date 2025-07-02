#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

tuple<int, int, int> find(unordered_map<int, vector<int>> &child, int i, string &s)
{
    tuple<int, int, int> ans = {0, 0, 0};
    if (s[i-1] == 'W')
        get<1>(ans) = 1;
    else
        get<2>(ans) = 1;
    for (auto e : child[i])
    {
        auto smallAns = find(child, e, s);
        get<0>(ans) += get<0>(smallAns);
        get<1>(ans) += get<1>(smallAns);
        get<2>(ans) += get<2>(smallAns);
    }
    if (get<1>(ans) == get<2>(ans))
        get<0>(ans)++;
    // cout << i << ' ' << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans) << endl;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        string s;
        cin >> n;
        unordered_map<int, vector<int>> child;
        for (int i = 2; i <= n; i++)
        {
            int par;
            cin >> par;
            child[par].push_back(i);
        }
        cin >> s;
        auto ans = find(child, 1, s);
        cout << get<0>(ans) << endl;
    }
    return 0;
}