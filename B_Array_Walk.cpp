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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int k, z, ans = 0, sum = 0;
        cin >> n >> k >> z;
        vector<int> v(n), pre(n);
        for (auto &e : v)
            cin >> e;

        for(int i = 0; i < n; i++)
            pre[i] = v[i] + (i-1 >= 0 ? pre[i-1] : 0);

        sum = v[0], k--;
        for (int i = 1; i < n && k >= 0; i++, k--)
        {
            sum += v[i];
            if (z)
            {
                int left = min(z, (k + 1) / 2), right = min(z, k / 2);
                int smallAns = sum + left * v[i-1] + right * v[i];

                if(k > z*2)
                    smallAns += pre[i+k - z*2] - pre[i];

                ans = max(smallAns, ans);
            }
            if(k == 0)
                ans = max(ans, sum);
        }

        cout << ans << endl;
    }
    return 0;
}

/*
3 2, 1
4 2 2
5 3 2
*/