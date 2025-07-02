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
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int i = (n - 1) / 2 - (n % 2), j = (n + 1) / 2;

        int increased = 0;
        bool valid = true;
        while (i >= 0)
        {
            v[i] += increased;
            if (v[i] > v[j])
            {
                valid = false;
                break;
            }
            else
            {
                increased += v[j] - v[i];
            }
            i--, j++;
        }
        if (valid)
        {
            cout << increased << endl;
        }
        else
            cout << "-1\n";
    }
    return 0;
}