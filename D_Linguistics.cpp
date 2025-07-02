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
#define um unordered_map

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solve(string &s, int i, um<int, um<int, um<int, int>>> &dp, int abf, int baf)
{
    if (abf == 0 && baf == 0)
        return 1;
    if (i == s.size())
        return -1;
    if (dp[i][abf][baf] == -1 || dp[i][abf][baf] == 1)
        return dp[i][abf][baf];

    int ans[3] = {-1};

    ans[0] = solve(s, i + 1, dp, abf, baf);
    if (abf > 0 && i + 1 < s.size() && s[i] == 'A' && s[i + 1] == 'B')
        ans[1] = solve(s, i + 2, dp, abf - 1, baf);
    else if (baf > 0 && i + 1 < s.size() && s[i] == 'B' && s[i + 1] == 'A')
        ans[2] = solve(s, i + 2, dp, abf, baf-1);

    int finalAns = -1;
    for (int i = 0; i < 3; i++)
    {
        if (ans[i] == 1)
            finalAns = ans[i];
    }
    dp[i][abf][baf] = finalAns;
    return finalAns;
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
        int af, bf, abf, baf;
        cin >> af >> bf >> abf >> baf;
        string s;
        cin >> s;
        um<int, um<int, um<int, int>>> dp;

        int reqa = 0, reqb = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
                reqa++;
            else
                reqb++;
        }

        if (reqa != af + abf + baf || reqb != bf + baf + abf)
        {
            cout << "NO\n";
            continue;
        }

        int finalAns = solve(s, 0, dp, abf, baf);

        if (finalAns == 1)
            out(true);
        else
            out(false);
    }
    return 0;
}

/*
5 4
BBABABABABBBABABABABABABAABABA

3 10

*/