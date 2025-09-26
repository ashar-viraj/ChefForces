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

int solve(string &s, char c, int n)
{
    vector<int> costUpToLeft(n, 0), costUpToRight(n, 0);

    int f = s[0] == c;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == c)
        {
            costUpToLeft[i] = costUpToLeft[i - 1];
            f++;
        }
        else
        {
            costUpToLeft[i] = costUpToLeft[i - 1] + f;
        }
    }

    f = s[n - 1] == c;

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == c)
        {
            costUpToRight[i] = costUpToRight[i + 1];
            f++;
        }
        else
        {
            costUpToRight[i] = costUpToRight[i + 1] + f;
        }
    }

    int cost = LLONG_MAX;

    for(int i = 0; i < n; i++) {
        cost = min(cost, costUpToLeft[i] + costUpToRight[i]);
    }

    return cost;
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
        string s;
        cin >> s;

        cout << min(solve(s, 'a', n), solve(s, 'b', n)) << endl;
    }
    return 0;
}