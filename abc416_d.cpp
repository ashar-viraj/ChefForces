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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);

        priority_queue<int> pq;
        for (auto &e : a)
            cin >> e;
        for (auto &e : b)
        {
            cin >> e;
            pq.push(e);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int a1 = 0, a2 = n - 1, b1 = 0, b2 = n - 1, ans = 0;

        while (a1 <= a2)
        {
            int s1 = (a[a1] + b[b1]) % m;
            int s2 = (a[a1] + b[b2]) % m;
            int s3 = (a[a2] + b[b1]) % m;
            int s4 = (a[a2] + b[b2]) % m;

            if (s1 <= min({s2, s3, s4}))
            {
                ans += s1;
                a1++, b1++;
            }
            else if (s2 <= min({s1, s3, s4}))
            {
                ans += s2;
                a1++, b2--;
            }
            else if (s3 <= min({s1, s2, s4}))
            {
                ans += s3;
                a2--, b1++;
            }
            else if (s4 <= min({s1, s2, s3}))
            {
                ans += s4;
                a2--, b2--;
            }
        }

        cout << ans << endl;
    }
    return 0;
}