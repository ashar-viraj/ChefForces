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
#define out(valid) cout << (valid ? "bES\n" : "NO\n")

const int a4[4] = {-1, 0, 1, 0}, b4[4] = {0, 1, 0, -1};
const int a8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, b8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

string solve(string &a, string &b)
{
    int m = a.length();
    int n = b.length();

    int LCS[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    int index = LCS[m][n];

    string lcs(index + 1, '\0');

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs[index - 1] = a[i - 1];
            i--;
            j--;

            index--;
        }

        else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}

// Returns longest palindromic subsequence
// of str
string longestPalSubseq(string &str)
{
    // Find reverse of str
    string rev = str;
    reverse(rev.begin(), rev.end());

    // Return LCS of str and its reverse
    return solve(str, rev);
}

int32_t main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string res = solve(s, rev);
        // int rem = res.size();
        // int max = n/2;
        // if(rem <= max)
        cout << res << endl;
    }
    return 0;
}