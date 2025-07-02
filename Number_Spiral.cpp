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
        int curr = max(n, m), ans;
        if (curr % 2)
        {
            if (n > m)
                ans = (curr - 1) * (curr - 1) + m;
            else
                ans = (curr - 1) * (curr - 1) + curr + curr - n;
        }
        else
        {
            if (n < m)
                ans = (curr - 1) * (curr - 1) + n;
            else
            {
                ans = (curr - 1) * (curr - 1) + curr + curr - m;
            }
        }
        cout << ans << endl;
    }
    return 0;
}