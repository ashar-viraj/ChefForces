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

void updateTree(vector<int> &tree, int left, int right, int idx, int node, int val)
{
    if (left == right)
    {
        tree[node] = val;
        return;
    }

    int mid = (left + right) / 2;
    if (idx <= mid)
        updateTree(tree, left, mid, idx, node * 2 + 1, val);
    else
        updateTree(tree, mid + 1, right, idx, node * 2 + 2, val);

    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

int query(vector<int> &tree, int start, int end, int left, int right, int node)
{
    if (end < left || right < start)
        return 0;

    if (start <= left && right <= end)
        return tree[node];

    int mid = (left + right) / 2;

    int leftAns = query(tree, start, end, left, mid, node * 2 + 1);
    int rightAns = query(tree, start, end, mid + 1, right, node * 2 + 2);

    return leftAns + rightAns;
}

void printSegTree(vector<int> &tree)
{
    for(int i = 0 ; i < tree.size(); i++)
    {
        cout << tree[i] << ' ';
        if(((i + 1) & (i + 2)) == 0)
            cout << endl;
    }
}

void bfs(vector<vector<int>> &al, int src, vector<int> &prev, vector<int> &dis, int n) {
    queue<int> q;

    q.push(src);
    dis[src] = 0;
    while(q.size()) {
        int curr = q.front();
        q.pop();

        for(auto e : al[curr]) {
            if(dis[e] != -1)
                continue;

            dis[e] = dis[curr] + 1;
            prev[e] = curr;
            q.push(e);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        vector<vector<int>> al(n+1);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            al[u].push_back(v);
            al[v].push_back(u);
        }

        vector<int> prevSrc(n+1, -1), prevDes(n+1, -1), disSrc(n+1, -1), disDes(n+1, -1);
        bfs(al, 1, prevSrc, disSrc, n);
        bfs(al, n, prevDes, disDes, n);

        int minDis = n+1, midNode = -1;
        for(int i = 1; i <= n; i++) {
            if(disSrc[i] != -1 && disSrc[i] == disDes[i] && disSrc[i] < minDis) {
                minDis = disSrc[i];
                midNode = i;
            }
        }

        if(midNode == -1)
        {
            cout << "-1\n";
            continue;
        }

        vector<int> ans;
        int curr = midNode;
        while(true) {
            ans.push_back(curr);
            if(curr == 1)
                break;
            curr = prevSrc[curr];
        };

        reverse(ans.begin(), ans.end());

        curr = prevDes[midNode];
        while(true) {
            ans.push_back(curr);
            if(curr == n)
                break;
            curr = prevDes[curr];
        };

        cout << ans.size() - 1 << endl;
        for(auto e : ans)
            cout << e << ' ';
        cout << endl;
    }
    return 0;
}