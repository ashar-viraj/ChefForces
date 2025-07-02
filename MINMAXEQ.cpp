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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int k;
        cin >> n >> k;
        int a[n];
        priority_queue<int> pq;
        rep(i, 0, n) cin >> a[i];
        vector<int> v;
        int freq = 1;
        for (i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                freq++;
                continue;
            }
            pq.push(freq);
            freq = 1;
        }
        pq.push(freq);
        while (k-- && pq.top() != 1)
        {
            int val = pq.top();
            pq.pop();
            pq.push(1);
            if (val == 2)
            {
                pq.push(1);
            }
            else if (val % 2)
            {
                pq.push(val / 2);
                pq.push(val / 2);
            }
            else
            {
                pq.push(val / 2);
                pq.push(val / 2 - 1);
            }
        }
        double ans = 0;
        while (pq.size())
        {
            ans += (pq.top() * (pq.top() + 1)) / 2;
            pq.pop();
        }
        cout << ans << endl;
    }
    return 0;
}