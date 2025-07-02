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
        int a, b, c, size;
        cin >> a >> b >> c;
        if (b < a)
            swap(a, b);
        size = (b - a) * 2;
        int valid = (a + size / 2) % size;
        if (valid == 0)
            valid = size;
        if (valid != b || c > size)
        {
            cout << "-1\n";
            continue;
        }
        int ans = (c + size / 2) % size;
        if (ans == 0)
            ans = size;
        cout << ans << endl;
    }
    return 0;
}