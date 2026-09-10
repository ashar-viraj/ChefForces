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
#define pb push_back
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

class Compare{
public:
    bool operator()(vector<int> &a, vector<int> &b) {
        if(a[1] != b[1])
            return a[1] > b[1];
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[2] > b[2];
    }
};

int setPq(vector<vector<int>> &al, int curr, vector<bool> &vis, int pathLen,
    priority_queue<vector<int>, vector<vector<int>>, Compare> &pq) {
    vis[curr] = true;
    int childs = 0;

    for(auto &e : al[curr]) {
        if(vis[e])
            continue;
        childs += setPq(al, e, vis, pathLen + 1, pq);
    }

    pq.push({childs, pathLen, curr});

    return childs + 1;
}

int solve(vector<vector<int>> &al, int curr, vector<bool> &vis, vector<bool> &tour, int &ans) {
    vis[curr] = true;
    int count = 0;

    for(auto e : al[curr]) {
        if(vis[e])
            continue;
        count += solve(al, e, vis, tour, ans);
    }

    if(tour[curr])
        ans += count;

    return count + !tour[curr];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1, i, j, n, m, itemp;
    // cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        int k;
        cin >> n >> k;
        vector<vector<int>> al(n+1);
        vector<bool> vis(n+1, false), tour(n+1, false);
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            al[u].pb(v);
            al[v].pb(u);
        }

        setPq(al, 1, vis, 0, pq);
        int need = n - k;
        while(need--) {
            auto top = pq.top();
            pq.pop();
            tour[top[2]] = true;
        }

        int ans = 0;
        fill(vis.begin(), vis.end(), false);
        solve(al, 1, vis, tour, ans);

        cout << ans << endl;
    }
    return 0;
}