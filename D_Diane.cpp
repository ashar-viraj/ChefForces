#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, n, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        string s = "";
        rep(i, 0, n / 2)
            s += 'a';
        s += 'b';
        rep(i, 0, n / 2 - 1)
            s += 'a';
        if (n % 2 && n != 1)
            s += 'c';
        cout << s << endl;
    }
    return 0;
}