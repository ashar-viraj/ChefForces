#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int k;
        cin >> n >> k;
        unordered_map<int, bool> used;
        if (k * 2 > n)
        {
            int replace = -1, j = 1;
            for (int i = 1; i <= k; i++)
            {
                if (k == n - 1 && n / 2 == i)
                {
                    if (i == j)
                    {
                        replace = i;
                        continue;
                    }
                    cout << n << ' ';
                    j++;
                    continue;
                }
                cout << i << ' ';
            }
            int replace2 = -1;
            for (int i = n; i > k; i--)
            {
                if (k == n - 1 && i == n)
                {
                    if (i == j)
                    {
                        replace2 = i;
                        continue;
                    }
                    j++;
                    cout << (n / 2) << ' ';
                    continue;
                }
                cout << i << ' ';
            }
            if (replace2 != -1)
                cout << replace2 << ' ';
            if (replace != -1)
                cout << replace << ' ';
            cout << endl;
            continue;
        }
        for (int i = 1; i <= k; i++)
        {
            cout << i * 2 << ' ';
            used[i * 2] = true;
        }
        int replace = -1, j = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
            {
                if (i == j + k)
                {
                    replace = i;
                    continue;
                }
                cout << i << ' ';
                j++;
            }
        }
        if (replace != -1)
        {
            cout << replace;
        }
        cout << endl;
    }
    return 0;
}