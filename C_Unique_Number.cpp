#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ans = 0, add = 1, digit = 1, digitchange = 0, count = 0;
        if (n > 45)
        {
            cout << "-1\n";
            continue;
        }
        while (count != n)
        {
            ans += add * digit;
            digitchange++;
            count++;
            if (digitchange == 9 - log10(digit))
            {
                add = 1;
                digit *= 10;
                digitchange = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}