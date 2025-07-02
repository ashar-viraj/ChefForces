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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        // cout << endl
        //      << tc << " : ";
        string a, b;
        cin >> a >> b;
        n = a.size(), m = b.size();
        if (a == b)
        {
            cout << "=\n";
            continue;
        }

        if (a[n - 1] == b[m - 1])
        {
            if (a.size() < b.size())
            {
                if (a[n - 1] == 'S')
                    cout << ">\n";
                else
                    cout << "<\n";
            }
            else
            {
                if (a[n - 1] == 'S')
                    cout << "<\n";
                else
                    cout << ">\n";
            }
            continue;
        }

        // if (a[0] == 'L' || b[n - 1] == 'S')
        //     swap(a, b);

        if ((a[n - 1] == 'S' && (b[m - 1] == 'M' || b[m - 1] == 'L')) || (a[n - 1] == 'M' && b[m - 1] == 'L'))
            cout << "<\n";
        else
            cout << ">\n";
    }
    return 0;
}