

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
        string s;
        cin >> n >> s;
        int ans = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int left = i, right = n - i - 1;
            if (s[i] == 'L')
            {
                pq.push(max(0ll, right - left));
                ans += left;
            }
            else
            {
                pq.push(max(0ll, left - right));
                ans += right;
            }
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            ans += pq.top();
            pq.pop();
            v[i] = ans;
        }
        for (auto e : v)
            cout << e << ' ';
        cout << endl;
    }
    return 0;
}
