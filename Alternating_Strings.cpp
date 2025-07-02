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
        int N = n;
        vector<int> v;
        int curr = 1;
        while (N > 0)
        {
            v.push_back(min(N, curr));
            N -= curr;
            curr++;
        }

        N = v.size();
        vector<int> prefix = v, suffix = v;

        for (int i = 1; i < N; i++)
            prefix[i] += prefix[i - 1];

        for (int i = N - 2; i >= 0; i--)
            suffix[i] += suffix[i + 1];

        // for(auto e : prefix) cout << e << ' ';
        // cout << endl;
        // for(auto e : suffix) cout << e << ' ';
        // cout << endl;

        int ans = 0;
        for (int i = 0; i < N - 1; i++)
        {
            int smallAns = (prefix[i] * suffix[i + 1]) % MOD;
            ans = (ans + smallAns) % MOD;
        }
        cout<< n << ' ' << ans << endl;
    }
    return 0;
}