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
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    int ans = 0;
    vector<vector<int>> v(n, vector<int>(2));
    rep(i, 0, n)
    {
        cin >> v[i][0] >> v[i][1];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        while (pq.size() && pq.top() <= v[i][0])
            pq.pop();
        pq.push(v[i][1]);

        ans = max(ans, (int)pq.size());
    }

    cout << ans << endl;

    return 0;
}

/*
2 4
3 9
5 8
*/