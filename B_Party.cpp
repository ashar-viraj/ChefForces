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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        vector<int> v(n);

        unordered_map<int, int> groups;
        unordered_map<int, vector<int>> mates;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> oddpq, evenpq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareHeapElements> pq;

        for (int i = 0; i < n; i++)
            cin >> v[i];

        int cakes = m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            mates[a].push_back(a);
            mates[b].push_back(b);
            groups[a]++;
            groups[b]++;
        }
        for (auto e : groups)
        {
            if (e.second == 0)
                continue;
            // if (e.second % 2)
            //     oddpq.push({e.first, e.second});
            // else
            //     evenpq.push({e.first, e.second});
            pq.push({e.first, e.second});
        }
        // if (tc == 4)
        //     cout << evenpq.size() << ' ' << oddpq.size() << " | \n";

        if (m % 2 == 0)
        {
            cout << 0 << endl;
            // cout << "ok1\n";
            continue;
        }

        int ans;
        if (oddpq.size())
        {
            int ans1, ans2 = 0;
            ans1 = oddpq.top().first;
            while (evenpq.size() > 0 && cakes % 2)
            {
                int rem = evenpq.top().first;
                evenpq.pop();
                cakes -= groups[rem];
                ans2 += rem;
                for (auto e : mates[rem])
                {
                    if (groups[e] != 0)
                        groups[e]--;
                }
                groups[rem] = 0;
            }
            while (oddpq.size() > 0 && cakes % 2)
            {
                int rem = oddpq.top().first;
                oddpq.pop();
                cakes -= groups[rem];
                ans2 += rem;
                for (auto e : mates[rem])
                {
                    if (groups[e] != 0)
                        groups[e]--;
                }
                groups[rem] = 0;
            }
            cout << min(ans1, ans2) << endl;
        }
        else
        {
            int ans2 = 0;
            cout << "cakes : ";
            while (evenpq.size() > 0 && cakes % 2)
            {
                int rem = evenpq.top().first;
                evenpq.pop();
                cakes -= groups[rem];
                ans2 += rem;
                for (auto e : mates[rem])
                {
                    if (groups[e] != 0)
                        groups[e]--;
                }
                groups[rem] = 0;
                cout << cakes << ' ';
            }
            cout << endl;
            while (oddpq.size() > 0 && cakes % 2)
            {
                int rem = oddpq.top().first;
                oddpq.pop();
                cakes -= groups[rem];
                ans2 += rem;
                for (auto e : mates[rem])
                {
                    if (groups[e] != 0)
                        groups[e]--;
                }
                groups[rem] = 0;
            }
            cout << ans2 << endl;
        }
        // cout << "ok " << tc << endl;
    }
    return 0;
}