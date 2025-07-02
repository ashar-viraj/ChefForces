#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> c(n);
        rep(i, 0, n)
        {
            cin >> c[i];
        }

        vector<int> a, b;
        bool valid = true;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a.size() == 0)
            {
                a.push_back(c[i]);
            }
            else if (b.size() == 0)
            {
                if (c[i] < a[a.size() - 1])
                    b.push_back(c[i]);
                else
                    a.push_back(c[i]);
            }
            else
            {
                if (c[i] < a[a.size() - 1] && c[i] < b[b.size() - 1])
                {
                    if (a[a.size() - 1] > b[b.size() - 1])
                        b.push_back(c[i]);
                    else
                        a.push_back(c[i]);
                }
                else if (c[i] < a[a.size() - 1])
                    b.push_back(c[i]);
                else if (c[i] < b[b.size() - 1])
                    a.push_back(c[i]);
                else
                {
                    valid = false;
                }
            }
        }

        if (a.size() == 0 || b.size() == 0 || !valid)
        {
            cout << "-1\n";
            continue;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        cout << a.size() << endl;
        for (auto e : a)
            cout << e << ' ';
        cout << endl
             << b.size() << endl;
        for (auto e : b)
            cout << e << ' ';
        cout << endl;
    }
    return 0;
}