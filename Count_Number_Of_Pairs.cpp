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

class A
{
public:
    int idx, pi;
};

bool compare(A &a, A &b)
{
    return a.pi < b.pi;
}

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
        vector<A> v(n + 1);
        v[0].idx = 0, v[0].pi = 0;

        for (int i = 1; i <= n; i++)
        {
            int val;
            cin >> val;
            v[i].idx = i;
            v[i].pi = val;
        }

        sort(v.begin(), v.end(), compare);

        int ans = 0;
        for(auto e : v)
            cout << e.idx << ' ';
        cout << endl;
        for(auto e : v)
            cout << e.pi << ' ';
        cout << endl;

        for (int i = 1; i <= n; i++)
        {
            cout << v[i].pi << " :: ";
            for (int j = 2 * i; j <= n; j += i)
            {
                int sidx = v[i].idx + v[j].idx;
                int spi = v[i].pi + v[j].pi;
                cout << sidx << ' ' << spi << " | ";
                ans += ((spi % sidx) == 0);
            }
            cout << endl;
        }
        cout << ans << ' ';

        for (int i = 1; i <= n; i++)
        {
            int sidx = v[i].idx + v[i].idx;
            int spi = v[i].pi + v[i].pi;
            ans += ((sidx % spi) == 0);
        }

        cout << ans << endl;
    }
    return 0;
}