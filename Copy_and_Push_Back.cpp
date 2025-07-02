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

bool solve(string &req, string s, bool app)
{
    // cout << req << ' ' << s << ' ' << app << ' ' << s.size() << ' ' << req[s.size()] << endl;
    if (s == req)
    {
        return true;
    }
    if (req.substr(0, s.size()) != s)
    {
        return false;
    }

    string oldString = s;
    bool ans = false;

    if (!app)
    {
        s += req[s.size()];
        ans |= solve(req, s, true);
    }

    s = oldString + oldString;
    if (s[0] == req[s.size() / 2])
    {
        ans |= solve(req, s, false);
    }

    return ans;
}

bool solve2(string &req)
{
    int n = req.size(), i = n-1;
    bool app = false, valid = true;
    if (n % 2)
    {
        app = true;
        i--;
    }
    while (i >= 0)
    {
        if (i % 2 == 0)
        {
            if (app)
            {
                // cout << "return 1 " << i << endl;
                return false;
            }
            app = true;
            i--;
        }
        else
        {
            int j = 0, k = (i + 1) / 2;
            // cout << j << ' ' << k << endl;
            while (k <= i)
            {
                if (req[j] != req[k])
                {
                    // cout << i << ' ' << req[j] << ' ' << req[k] << endl;
                    return false;
                }
                j++, k++;
            }
            i /= 2;
            app = false;
        }
    }
    return true;
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        string req;
        cin >> req;
        // cout << endl;
        if (n == 1)
        {
            cout << "YES\n";
            continue;
        }
        // string s = "";
        // s += req[0];
        bool ans = solve2(req);
        out(ans);
    }
    return 0;
}