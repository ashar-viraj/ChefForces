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
        int count = 1, ans, i = 1;
        while (i <= n)
        {
            if (count % 3 == 0 || count % 10 == 3)
            {
                count++;
                continue;
            }
            ans = count;
            i++;
            count++;
        }
        cout << ans << endl;
    }
    return 0;
}