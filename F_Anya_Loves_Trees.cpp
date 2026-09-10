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

// min max poss
vector<int> solve(vector<vector<int>> &al, int curr, vector<int> &val) {
    if(al[curr].empty())
        return {val[curr], val[curr], 1};

    vector<vector<int>> childrenAns;

    for(auto &e : al[curr]) {
        childrenAns.push_back(solve(al, e, val));
        if(!childrenAns.back()[2])
            return {0, 0, 0};
    }

    // cout << curr << " => ";
    // for(auto e : childrenAns)
    //     cout << e[0] << ' ' << e[1] << ' ' << e[2] << " | ";
    // cout << endl;

    int mi = childrenAns[0][0], ma = childrenAns[0][1];
    bool isPoss = true;

    int idx = 1, n = childrenAns.size();
    while(idx < n && childrenAns[idx - 1][1] < childrenAns[idx][0]) {
        mi = min(mi, childrenAns[idx][0]);
        ma = max(ma, childrenAns[idx][1]);
        idx++;
    }
    if(idx == n)
        return {childrenAns[0][0], childrenAns.back()[1], 1};

    mi = min(mi, childrenAns[idx][0]);
    ma = max(ma, childrenAns[idx][1]);
    idx++;
    while(idx < n && childrenAns[idx - 1][1] < childrenAns[idx][0]) {
        mi = min(mi, childrenAns[idx][0]);
        ma = max(ma, childrenAns[idx][1]);
        idx++;
    }

    if(idx != n || childrenAns.back()[1] >= childrenAns[0][0]) {
        // cout << "INVALID : " << curr << ' ' << (idx != n) << ' ' << (childrenAns.back()[1] <= childrenAns[0][0]) << endl;
        return {0, 0, 0};
    }

    return {mi, ma, 1};
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<vector<int>> child(n+1);
        for(int i = 2; i <= n; i++) {
            int par;
            cin >> par;

            child[par].push_back(i);
        }

        vector<int> val(n+1);
        for(int i = 1; i <= n; i++)
            cin >> val[i];

        out(solve(child, 1, val)[2]);
    }
    return 0;
}