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

vector<int> palindromes;

int solve(int i, int n, unordered_map<int, int> &dp)
{
    cout << i << ' ' << n << " : ";
    string s;
    // getline(cin, s);
    if (dp[n] != -1)
    {
        return dp[n];
    }
    if (n == 0)
    {
        return 1;
    }
    if (n < 0 || palindromes[i] > n)
        return 0;

    int ans = 0;
    for (int j = 0; ((palindromes[i] * j) <= n); j++)
    {
        int smallAns = solve(i + 1, n - (j * palindromes[i]), dp);
        ans = (ans + smallAns) % MOD;
    }

    dp[n] = ans % MOD;
    return (ans % MOD);
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;

    unordered_map<int, int> dp;
    for (int i = 1; i <= 4 * pow(10, 4); i++)
    {
        string s = to_string(i), rev = s;
        reverse(s.begin(), s.end());
        if (s == rev)
            palindromes.push_back(i);
        dp[i] = -1;
    }
    for(int i = 0; i < 10; i++) cout << palindromes[i] << ' ';
    cout << endl;
    dp[1] = 1;
    for (int i = 2; i <= 5; i++)
        dp[i] = solve(0, i, dp);
    for (int i = 1; i <= 5; i++)
        cout << dp[i] << ' ';
    cout << endl;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}