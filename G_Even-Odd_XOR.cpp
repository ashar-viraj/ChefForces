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
        int on = (n + 1) / 2, en = n / 2;
        vector<int> a(on), b(en);
        int os = 1, es = 1;
        es = (es << 1);
        int len = 0;
        i = 1;
        while (i < 32)
        {
            if (((1 << i) & on) == (1 << i))
                len = i;
            i++;
        }

        while (len--)
            es = (es << 1);

        for (int i = 0; i < on; i++, os++)
            a[i] = os;
        for (int i = 0; i < en; i++, es++)
            b[i] = es |;
    }
    return 0;
}