#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map<int, bool>
#define MOD 1000000007
#define f first
#define s second
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solve(vector<string> &v, int rem, um &d1, um &d2, um &row, um &col)
{
    if (rem == 7)
        return 1;

    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        if (row[i])
            continue;
        for (int j = 0; j < 8; j++)
        {
            if (v[i][j] == '*' || col[j] || d1[i + j] || d2[i - j])
                continue;

            row[i] = true;
            col[j] = true;
            d1[i + j] = true;
            d2[i - j] = true;

            ans += solve(v, rem - 1, d1, d2, row, col);

            row[i] = false;
            col[j] = false;
            d1[i + j] = false;
            d2[i - j] = false;
        }
    }

    return ans;
}

int32_t main()
{
    vector<string> v(8);
    for (int i = 0; i < 8; i++)
        cin >> v[i];

    um d1, d2, row, col;
    cout << solve(v, 8ll, d1, d2, row, col);
    return 0;
}