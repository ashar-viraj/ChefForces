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

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void build(vector<string> &s, int k, vector<string> &t, vector<string> &curr)
{
    if (k == 0)
    {
        string final = "";
        for (auto e : curr)
            final += e;

        t.pb(final);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        curr.push_back(s[i]);
        build(s, k - 1, t, curr);
        curr.pop_back();
    }
}

int32_t main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<string> t, curr;
    build(s, k, t, curr);

    sort(t.begin(), t.end());

    cout << t[x - 1];

    return 0;
}