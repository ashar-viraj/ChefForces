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
        string s, t;
        cin >> s >> t;
        vector<int> zz(n+1, 0);
        vector<int> zo(n+1, 0);
        vector<int> oz(n+1, 0);
        vector<int> oo(n+1, 0);

        for(int i = 1; i <= n; i++) {
            zz[i] = zz[i-1];
            zo[i] = zo[i-1];
            oz[i] = oz[i-1];
            oo[i] = oo[i-1];

            if(s[i-1] == '0' && t[i-1] == '0') zz[i]++;
            if(s[i-1] == '0' && t[i-1] == '1') zo[i]++;
            if(s[i-1] == '1' && t[i-1] == '0') oz[i]++;
            if(s[i-1] == '1' && t[i-1] == '1') oo[i]++;
        }

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            int need = abs((zo[v] - zo[u-1]) - (oz[v] - oz[u-1]));
            int avail = zz[v] - zz[u-1] + oo[v] - oo[u-1];

            out(avail >= need);
        }
    }
    return 0;
}