#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

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
        string s;
        cin >> s;
        if (n % 2)
        {
            cout << "NO\n";
            continue;
        }
        int f0 = 0, f1 = 0;
        for (auto e : s)
        {
            f0 += (e == '0');
            f1 += (e == '1');
        }
        if (f0 == f1)
        {
            cout << "YES\n1 " << n << endl;
            continue;
        }
        char ch = '1';
        int req = abs(f0 - f1) / 2;
        if (f0 > f1)
            ch = '0';
        int l = 0, r = 0;
        while (s[l] != ch)
            l++;
        r = l;
        int sum = 1;
        // cout << 
        while (sum != req && r + 1 < n)
        {
            if (s[r + 1] == ch)
                sum++;
            else
                sum--;
            r++;
            if (sum == 0)
            {
                l = r;
                while (s[l] != ch)
                    l++;
                r = l;
                // cout << l << ' ' << r << endl;
                sum = 1;
            }
        }
        cout << "YES\n";
        cout << l + 1 << ' ' << r + 1 << endl;
    }
    return 0;
}