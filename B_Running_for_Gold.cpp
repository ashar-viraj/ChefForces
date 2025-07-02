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

    int t, i, j, n, itemp, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n+1][5];
        rep(i, 1, n+1)
        {
            rep(j, 0, 5)
            {
                cin >> a[i][j];
            }
        }
        int count, ans = 1;
        rep(i, 2, n+1)
        {
            count = 0;
            rep(j, 0, 5)
            {
                if(a[i][j] < a[ans][j])
                    count++;
            }
            if(count >= 3)
            {
                ans = i;
            }
        }
        rep(i, 1, n+1)
        {
            if(ans == i)
                continue;
            count = 0;
            rep(j, 0, 5)
            {
                if(a[i][j] > a[ans][j])
                    count++;
            }
            if(count < 3)
            {
                ans = -1;
                break;
            }
        }
        cout << ans << endl;

    }
    return 0;
}