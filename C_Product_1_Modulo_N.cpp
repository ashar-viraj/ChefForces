#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    cin >> n;
    bool valid[n];
    memset(valid, true, sizeof(valid));
    int product = 1;
    rep(i, 1, n)
    {
        if (gcd(i, n) != 1)
            valid[i] = false;
        else
        {
            product *= i;
            product %= n;
        }
    }
    if (product % n != 1)
    {
        valid[product] = false;
    }
    vector<int> ans;
    rep(i, 1, n)
    {
        if (valid[i])
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e << " ";
    cout << endl;
    return 0;
}