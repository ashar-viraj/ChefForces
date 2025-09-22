#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
#define f first
#define s second
#define pb push_back
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        if (a == 0 || b == 0 || (a + b > n))
        {
            out(a == 0 && b == 0 && a + b <= n);
            if (a == 0 && b == 0)
            {
                for (int i = 1; i <= n; i++)
                    cout << i << ' ';
                cout << endl;
                for (int i = 1; i <= n; i++)
                    cout << i << ' ';
                cout << endl;
            }
            continue;
        }

        int total = a + b;
        out(1);
        for (int i = b + 1; i <= total; i++)
            cout << i << ' ';

        for (int i = 1; i <= b; i++)
            cout << i << ' ';

        for (int i = total + 1; i <= n; i++)
            cout << i << ' ';

        cout << endl;
        for (int i = 1; i <= n; i++)
            cout << i << ' ';

        cout << endl;
    }
    return 0;
}