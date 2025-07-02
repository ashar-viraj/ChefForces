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
        vector<int> v(n);
        int max = 0, ans = -1;
        rep(i, 0, n)
        {
            cin >> v[i];
            if (v[i] > max)
            {
                max = v[i];
            }
        }
        rep(i, 0, n)
        {
            if (v[i] == max)
            {
                if (i == 0)
                {
                    if (v[1] != max)
                    {
                        ans = i + 1;
                        break;
                    }
                }
                else if (i == n - 1)
                {
                    if (v[n - 2] != max)
                    {
                        ans = i + 1;
                        break;
                    }
                }
                else if (v[i - 1] != max || v[i + 1] != max)
                {
                    ans = i + 1;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}