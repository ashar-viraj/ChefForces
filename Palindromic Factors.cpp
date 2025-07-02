#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

void factors(int n)
{
    vector<int> ans;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if(i*i != n)
                ans.push_back(n / i);
        }
    }
    int poss = 0;
    for (auto e : ans)
    {
        string s = to_string(e);
        string s2 = s;
        reverse(s2.begin(), s2.end());
        if (s == s2)
            poss++;
    }
    cout << poss << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        cin >> n;
        factors(n);
    }
    return 0;
}