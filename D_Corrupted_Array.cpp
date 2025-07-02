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
        vector<int> v(n + 2);
        int sum = 0, skippos;
        rep(i, 0, n + 2)
        {
            cin >> v[i];
            sum += v[i];
        }
        sort(v.begin(), v.end());
        bool found = false;
        if (sum - (v[n] + v[n + 1]) == v[n])
        {
            rep(i, 0, n)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        else
        {
            sum -= v[n + 1];
            rep(i, 0, n + 1)
            {
                if (sum - v[i] == v[n+1])
                {
                    found = true;
                    skippos = i;
                    break;
                }
            }
            if (found)
            {
                rep(i, 0, n + 1)
                {
                    if (i == skippos)
                        continue;
                    cout << v[i] << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
    return 0;
}

// 73300
// 84800