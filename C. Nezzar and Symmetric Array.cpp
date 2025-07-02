#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (i = a; i < b; i++)
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, temp, a, b, c, d;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v(2 * n);
        map<int, int> possArr;
        rep(i, 0, 2 * n)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        bool possible = true;
        int count = 2 * n, sum = 0;
        for (i = 2 * n - 1; i >= 0; i -= 2)
        {
            if (sum - v[i] == 0 || v[i] != v[i - 1] || (v[i] - sum) < 0)
            {
                possible = false;
                break;
            }
            if ((v[i] - sum) % count == 0)
            {
                if (possArr[(v[i] - sum) / count] || possArr[(-1) * ((v[i] - sum) / count)])
                {
                    possible = false;
                    break;
                }
                possArr[(v[i] - sum) / count]++;
                possArr[(-1) * ((v[i] - sum) / count)];
                sum += (2 * ((v[i] - sum) / count));
                count -= 2;
            }
            else
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
