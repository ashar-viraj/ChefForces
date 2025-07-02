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

class Solution
{
public:
    vector<long long> countBlackBlocks(int n, int m, vector<vector<int>> &mat)
    {
        vector<long long> ans(5, 0);
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (auto e : mat)
        {
            v[e[0]][e[1]] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                int black = v[i][j] + v[i - 1][j - 1] + v[i - 1][j] + v[i][j - 1];
                ans[black]++;
            }
        }

        return ans;
    }
};

int32_t main()
{
    Solution ob;
    vector<vector<int>> mat = {{0, 0}, {1, 1}, {0, 2}}, m = {{0, 0}};
    auto v = ob.countBlackBlocks(3, 3, mat);
    for (auto e : v)
        cout << e << ' ';
    cout << endl;
    v = ob.countBlackBlocks(3, 3, m);
    for (auto e : v)
        cout << e << ' ';
    cout << endl;
    return 0;
}