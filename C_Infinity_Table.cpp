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
        int s = ceil(sqrt((double)n)), c, r;
        if (n - (s - 1) * (s - 1) < s)
            c = s, r = n - (s - 1) * (s - 1);
        else if (n - (s - 1) * (s - 1) > s)
            r = s, c = (s) * (s)-n + 1;
        else
            r = s, c = s;
        cout << r << " " << c << endl;
    }
    return 0;
}