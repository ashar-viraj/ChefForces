#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007

ll solve(ll n, unordered_map<ll, ll> &dp, vector<ll> &choices, int i)
{
    // string s;
    // getline(cin, s);
    // cout << n << ' ' << i << ' ' << choices[i];
    if (i == choices.size())
        return -1;
    if (n < 0)
        return -1;
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans = -1, tempAns = -1;

    if (choices[i] <= n)
        tempAns = solve(n, dp, choices, i + 1);
    if (tempAns != -1)
        ans = tempAns + 1;
    if (n - choices[i] >= 0)
    {
        tempAns = solve(n - choices[i], dp, choices, i + 1);
        if (tempAns != -1)
        {
            if (ans == -1)
                ans = tempAns + 1;
            else
                ans = min(ans, tempAns + 1);
        }
    }

    dp[n] = ans;
    return ans;
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll t, i, j, n, m, itemp;
    cin >> t;
    unordered_map<ll, ll> dp;
    vector<ll> choices;
    vector<ll> pow2, fact;
    ll pow = 1, fac = 1;
    for (ll i = 0; i < 40; i++)
    {
        choices.push_back(pow);
        pow *= 2;
    }
    for (ll i = 2; i < 15; i++)
    {
        choices.push_back(fac);
        fac *= i;
    }
    sort(choices.begin(), choices.end());
    dp[0] = 1;

    cout << pow2.size() << '|' << fact.size() << endl;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        ll ans = solve(n, dp, choices, 0);
        cout << ans << endl;
    }
    return 0;
}