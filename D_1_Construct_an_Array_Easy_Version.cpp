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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        vector<vector<int>> res(m, vector<int>(3)), al(n+1, vector<int>(n+1, 1));
        vector<int> ans(n+1, n*n);
        for(int i = 0; i < m; i++) {
            cin >> res[i][0] >> res[i][1] >> res[i][2];
            if(res[i][1] == res[i][2] && res[i][0] == 2)
                ans[res[i][1]] *= -1;
            al[res[i][1]][res[i][2]] = res[i][0];
        }

        bool valid = true;

        for(int u = 1, step = n+1; u <= n; u++, step--) {
            for(int v = u+1; v <= n; v++) {
                int o = al[u][v];
                if(o == 1) {
                    if(ans[v] + ans[u] < 0)
                        ans[v] = -ans[u];
                } else if(o == 2) {
                    if(ans[v] + ans[u] >= 0)
                        ans[v] = -ans[u] - step;
                }
            }
        }

        for(int u = 1; u <= n; u++) {
            for(int v = u; u <= n; u++) {
                if((al[u][v] == 1 && (ans[u] + ans[v]) >= 0) || al[u][v] == 2 && (ans[u] + ans[v]) < 0)
                    continue;
                valid = false;
            }
        }

        out(valid);
        if(!valid)
            continue;
        for(int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}