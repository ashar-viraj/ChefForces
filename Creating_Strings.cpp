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
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve(string &s, string &gen, int i, int n, vector<string> &ans, unordered_map<string, bool> &isThere)
{
    if (i == n)
    {
        // cout << gen << ' ' << isThere[gen];
        if (!isThere[gen])
        {
            // cout << " Not There";
            isThere[gen] = true;
            ans.push_back(gen);
        }
        // cout << endl;
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (s[j] != '.')
        {
            char old = s[j];
            s[j] = '.';
            gen.push_back(old);

            solve(s, gen, i + 1, n, ans, isThere);

            gen.pop_back();
            s[j] = old;
        }
    }
}

int32_t main()
{
    string s;
    cin >> s;

    string gen = "";
    vector<string> ans;
    unordered_map<string, bool> isThere;

    int n = s.size();
    solve(s, gen, 0, n, ans, isThere);

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e << endl;

    return 0;
}