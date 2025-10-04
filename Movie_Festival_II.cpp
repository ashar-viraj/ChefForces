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
    int n, m;

    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(2));

    for (auto &e : v)
        cin >> e[1] >> e[0];

    sort(v.begin(), v.end());

    multiset<int> s;

    int ans = 0;

    for (auto e : v)
    {
        auto itr = s.upper_bound(e[1]);
        if (s.size() && itr != s.begin())
        {
            // cout << e[0] << ' ' << e[1] << endl;
            itr--;
            s.erase(itr);
            s.insert(e[0]);
            ans++;
        }
        else if (s.size() < m)
        {
            // cout << e[0] << ' ' << e[1] << endl;
            s.insert(e[0]);
            ans++;
        }
    }

    cout << ans;

    return 0;
}

/*
69 57 1
72 35 2
78 53 3
79 77 1
87 49 4
90 80 2
94 75 5
95 46
95 64
99 22


57 69 1
35 72 2
53 78 3
77 79 2
49 87 4
80 90 2
75 94 1
46 95 5

(10, (64, 95)),
(9, (22, 99))]

({8: 1,
7: 2,
3: 3,
4: 2,
6: 4,
2: 2,
5: 1,
1: 5}, 8)
*/