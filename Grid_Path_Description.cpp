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

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1}; // U, R, D, L
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solve(int i, int j, int k, int remain, string &s, vector<vector<bool>> &vis)
{
    cout << i << ' ' << j << ' ' << remain << endl;
    if (remain == 0)
    {
        return 1;
    }

    if (i < 0 || j < 0 || i == 7 || j == 7)
        return 0;

    int ans = 0;
    vis[i][j] = true;
    if (s[k] == '?')
    {
        for (int l = 0; l < 4; l++)
        {
            ans += solve(i + x4[l], j + y4[l], k + 1, remain - 1, s, vis);
        }
    }
    else
    {
        int k = 0;
        if (s[k] == 'U')
            k = 0;
        else if (s[k] == 'R')
            k = 1;
        else if (s[k] == 'D')
            k = 2;
        else if (s[k] == 'L')
            k = 3;

        ans += solve(i + x4[k], j + y4[k], k + 1, remain - 1, s, vis);
    }

    vis[i][j] = false;

    return ans;
}

int32_t main()
{
    string s;
    cin >> s;

    vector<vector<bool>> vis(7, vector<bool>(7, false));
    int ans = solve(0, 0, 0, 49, s, vis);

    cout << ans;
    return 0;
}