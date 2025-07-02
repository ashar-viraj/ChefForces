#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

bool checkl(string s, string t, int i, int j)
{
    if (j == t.size())
        return true;
    if (s[i] != t[j])
        return false;
    bool valid = false;
    if (i == 0)
    {
        if (j == t.size() - 1)
            return true;
        else
            return false;
    }
    valid = checkl(s, t, i - 1, j + 1);
    return valid;
}

bool checkr(string s, string t, int i, int j)
{
    bool valid = false;
    if (j == t.size())
        return true;
    if (s[i] != t[j])
        return false;
    if (i == s.size())
        valid = checkl(s, t, i - 2, j);
    else
    {
        valid = checkr(s, t, i + 1, j + 1);
        if (valid)
            return valid;
        valid = checkl(s, t, i - 1, j + 1);
    }
    return valid;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        bool valid = false;
        rep(i, 0, s.size())
        {
            if (t[0] == s[i])
            {
                valid = checkr(s, t, i, 0);
            }
            if (valid)
                break;
        }
        cout << (valid ? "YES\n" : "NO\n");
    }
    return 0;
}