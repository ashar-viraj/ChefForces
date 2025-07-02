#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
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
        rep(i, 0, n) cin >> v[i];
        sort(v.begin(), v.end());
        vector<int> a(n), b(n), c(n);
        i = 1, j = n - n / 2;
        int k = 1;
        a[0] = v[0];
        while (k < n)
        {
            if (j < n && abs(v[j] - a[k - 1]) > abs(a[k - 1] - v[i]))
                a[k++] = v[j++];
            else
                a[k++] = v[i++];
        }
        int diff = INT_MAX, ans1 = 0, ans2 = 0, ans3 = 0;
        rep(i, 1, n) diff = min(diff, abs(a[i] - a[i - 1]));
        ans1 = diff;
        if (n % 2)
        {
            b[0] = v[0];
            i = 0, j = n - n / 2 + 1;
            k = 0;
            while (k < n)
            {
                if (j < n && abs(v[j] - b[k - 1]) > abs(b[k - 1] - v[i]))
                    b[k++] = v[j++];
                else
                    b[k++] = v[i++];
            }
            diff = INT_MAX;
            rep(i, 1, n) diff = min(diff, abs(b[i] - b[i - 1]));
            ans2 = diff;
            i = 0, j = n - n / 2;
            c[0] = v[j];
            j++;
            k = 1;
            while (k < n)
            {
                if (j < n && abs(v[j] - c[k - 1]) > abs(c[k - 1] - v[i]))
                    c[k++] = v[j++];
                else
                    c[k++] = v[i++];
            }
            diff = INT_MAX;
            rep(i, 1, n) diff = min(diff, abs(b[i] - b[i - 1]));
            ans2 = diff;
        }
        if (ans1 < ans2 && ans2 > ans3)
            for (auto e : b)
                cout << e << ' ';
        else if (ans1 > ans3 && ans1 > ans2)
            for (auto e : a)
                cout << e << ' ';
        else
            for (auto e : c)
                cout << e << ' ';
        cout << endl;
    }
    return 0;
}