#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        priority_queue<int, vector<int>, greater<int>> a;
        priority_queue<int> b;

        for(int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            a.push(val);
        }
        for(int i = 0; i < m; i++)
        {
            int val;
            cin >> val;
            b.push(val);
        }

        int ans = 0;
        while(b.size() && a.size())
        {
            ans += b.top();
            a.pop();
            b.pop();
        }
        // cout << ans << ' ' << a.size() << endl;
        // continue;
        while(!a.empty())
        {
            ans += a.top();
            a.pop();
        }

        cout << ans << endl;
    }
    return 0;
}