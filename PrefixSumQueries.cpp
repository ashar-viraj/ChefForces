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

void updateTree(vector<pair<int, int>> &tree, int left, int right, int idx, int node, int val)
{
    if (left == right)
    {
        tree[node].f = max(0ll, val);
        tree[node].s = val;
        return;
    }

    int mid = (left + right) / 2;
    if (idx <= mid)
        updateTree(tree, left, mid, idx, node * 2 + 1, val);
    else
        updateTree(tree, mid + 1, right, idx, node * 2 + 2, val);

    tree[node].f = max(tree[node * 2 + 1].f, tree[node*2 + 1].s + tree[node * 2 + 2].f);
    tree[node].s = tree[node*2 + 1].s + tree[node * 2 + 2].s;
}

pair<int, int> query(vector<pair<int, int>> &tree, int start, int end, int left, int right, int node)
{
    if (end < left || right < start)
        return {0, 0};

    if (start <= left && right <= end)
        return {tree[node].f, tree[node].s};

    int mid = (left + right) / 2;

    auto leftAns = query(tree, start, end, left, mid, node * 2 + 1);
    auto rightAns = query(tree, start, end, mid + 1, right, node * 2 + 2);

    int maxPref = max(leftAns.f, leftAns.s + rightAns.f);
    return {maxPref, leftAns.s + rightAns.s};
}

void printSegTree(vector<pair<int, int>> &tree)
{
    for(int i = 0 ; i < tree.size(); i++)
    {
        cout << tree[i].f << ' ';
        if(((i + 1) & (i + 2)) == 0)
            cout << endl;
    }
    cout << "\n###############################\n";

    for(int i = 0 ; i < tree.size(); i++)
    {
        cout << tree[i].s << ' ';
        if(((i + 1) & (i + 2)) == 0)
            cout << endl;
    }
    cout << "\n###############################\n";
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<int, int>> tree(n*4, {0, 0});
    for(auto &e : v)
        cin >> e;

    for(int i = 0; i < n; i++)
        updateTree(tree, 0, n-1, i, 0, v[i]);

    int a, b, type;
    for(int i = 0; i < m; i++) {
        cin >> type >> a >> b;
        if(type == 1)
            updateTree(tree, 0, n-1, a-1, 0, b);
        else
            cout << query(tree, a-1, b-1, 0, n-1, 0).f << endl;
    }

    return 0;
}