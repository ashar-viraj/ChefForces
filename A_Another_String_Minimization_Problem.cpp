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
        int q;
        cin >> n >> q;
        string s = "";
        for (int i = 0; i < q; i++)
        {
            s += 'B';
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i]--;
            int mi = min(v[i], q - v[i] - 1);
            int ma = max(v[i], q - v[i] - 1);
            if (s[mi] != 'A')
                s[mi] = 'A';
            else
                s[ma] = 'A';
        }
        cout << s << endl;
    }
    return 0;
}