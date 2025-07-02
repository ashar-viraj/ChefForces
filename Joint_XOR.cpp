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

int findAns(string c)
{
    int ans = 0;
    int pow2 = 1;
    int two = 2;
    int n = c.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (c[i] == '1')
            ans = (ans + pow2) % MOD;
        pow2 = (pow2 * two) % MOD;
    }

    return ans;
}

int32_t main()
{
    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        string s;
        cin >> s;
        string a = "", b = "";
        int i = 0, j = 0;
        while (j < n && s[j] == s[i])
            j++;

        int startIdx = j;
        while (j < n)
            b += s[j++];

        string reqS = "";
        for (auto e : b)
        {
            if (e == '0')
                reqS += '1';
            else
                reqS += '0';
        }

        i = 0;
        while (i < b.size() && b[i] == b[0])
            i++;

        j = startIdx;
        while (j >= 0 && i >= 0 && s[j] == reqS[i])
        {
            j--, i--;
        }
        j++;
        cout << j << ' ';

        while (a.size() != b.size())
        {
            a += s[j++];
        }

        cout << a << ' ' << b << ' ' << reqS << ' ' << startIdx << endl;

        string c = "";
        i = 0;
        while (i < b.size())
        {
            if (a[i] == b[i])
                c += '0';
            else
                c += '1';
            i++;
        }

        cout << findAns(c) << endl;
    }
    return 0;
}