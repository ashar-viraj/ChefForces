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

    tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
}

int query(vector<int> &tree, int start, int end, int left, int right, int node)
{
    if (end < left || right < start)
        return INT_MAX;

    if (start <= left && right <= end)
        return tree[node];

    int mid = (left + right) / 2;

    int leftAns = query(tree, start, end, left, mid, node * 2 + 1);
    int rightAns = query(tree, start, end, mid + 1, right, node * 2 + 2);

    return min(leftAns, rightAns);
}

void printSegTree(vector<int> &tree)
{
    for(int i = 0 ; i < tree.size(); i++)
    {
        cout << (tree[i] == INT_MAX ? "INF" : to_string(tree[i])) << ' ';
        if(((i + 1) & (i + 2)) == 0)
            cout << endl;
    }
    cout << "\n#######################\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &e : v) cin >> e;

    vector<int> prefCost = v, postCost = v, preTree(n*4, INT_MAX), postTree(n*4, INT_MAX);
    for(int i = 0; i < n; i++) {
        prefCost[i] += i;
        postCost[i] += n - i - 1;
    }

    for(int i = 0; i < n; i++) {
        updateTree(preTree, 0, n-1, i, 0, prefCost[i]);
        updateTree(postTree, 0, n-1, i, 0, postCost[i]);
    }

    int type, idx, val;
    for(int i = 0; i < m; i++) {
        cin >> type;
        if(type == 2) {
            cin >> idx;
            idx--;
            int preAns = query(preTree, idx, n-1, 0, n-1, 0) - idx;
            int postAns = query(postTree, 0, idx, 0, n-1, 0) - (n - idx - 1);

            cout << min(preAns, postAns) << endl;
        } else {
            cin >> idx >> val;
            idx--;
            prefCost[idx] = val + idx;
            postCost[idx] = val + n - idx - 1;
            updateTree(preTree, 0, n-1, idx, 0, prefCost[idx]);
            updateTree(postTree, 0, n-1, idx, 0, postCost[idx]);
        }
    }

    return 0;
}