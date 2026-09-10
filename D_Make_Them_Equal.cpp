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

int solve(vector<int> &b, vector<int> &c, int i, int k, vector<vector<int>> &dp) {
    if(i < 0)
        return 0;

    if(dp[i][k] != -1)
        return dp[i][k];

    int inc = 0, exc = solve(b, c, i-1, k, dp);
    if(b[i] <= k)
        inc = solve(b, c, i-1, k-b[i], dp) + c[i];

    return dp[i][k] = max(inc, exc);
}

int32_t main()
{
    int t, i, j, n, m, itemp;
    cin >> t;

    vector<int> costToReach(1001, INT_MAX);
    costToReach[1] = 0;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= i; j++) {
            int val = i + i/j;
            if(val <= 1000)
                costToReach[val] = min(costToReach[val], costToReach[i] + 1);
        }
    }

    for(auto tc = 1; tc <= t; tc++)
    {
        int k, need = 0;
        cin >> n >> k;
        vector<int> b(n), c(n);
        for(auto &e : b) {
            cin >> e;
            e = costToReach[e];
            need += e;
        }
        for(auto &e : c)
            cin >> e;

        if(need <= k)
        {
            cout << accumulate(c.begin(), c.end(), 0) << endl;
            continue;
        }

        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        cout << solve(b, c, n-1, k, dp) << endl;
    }
    return 0;
}