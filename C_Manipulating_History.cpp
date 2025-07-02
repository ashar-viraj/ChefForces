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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<string> v(2 * n);
        string s;
        for (int i = 0; i < 2 * n; i++)
            cin >> v[i];
        cin >> s;

        unordered_map<string, bool> par;

        for (int i = 1; i < 2 * n; i++)
            par[v[i]] = true;

        queue<string> req;
        req.push(s);
        while(req.size())
        {
            int qsize = req.size();
            while(qsize--)
            {
                string s = req.front();
                req.pop();

                queue<string

            }
        }
    }
    return 0;
}