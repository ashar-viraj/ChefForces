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

int getLIdx(vector<vector<int>> &target, int l) {
    int n = target.size(), lo = 0, hi = n-1, ans = n;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(target[mid][1] < l) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
            ans = mid;
        }
    }

    return ans;
}

int getRIdx(vector<vector<int>> &target, int r) {
    int n = target.size(), lo = 0, hi = n-1, ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;

        if(target[mid][0] <= r) {
            lo = mid + 1;
            ans = mid;
        } else {
            hi = mid - 1;
        }
    }

    return ans;
}

void solve(string &s, string &target, vector<vector<int>> &queries, vector<bool> &ans) {
    int n = s.size();
    vector<vector<int>> range;
    int l = -1, r = -1;
    for(int i = 0; i < n; i++) {
        if(target[i] == s[i]) {
            if(r != -1)
                range.push_back({l, r});
            l = -1, r = -1;
        } else {
            if(l == -1)
                l = i;
            r = i;
        }
    }

    if(r != -1)
        range.push_back({l, r});

    for(int i = 0; i < queries.size(); i++) {
        int l = queries[i][0], r = queries[i][1], k = queries[i][2];
        int lIdx = getLIdx(range, l), rIdx = getRIdx(range, r);
        int diff = INT_MAX;
        if(lIdx <= rIdx) {
            diff = rIdx - lIdx + 1;
        }
        else if(k == 0 || range.empty())
            diff = 0;

        ans[i] = ans[i] | (diff <= k);
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
        string s;
        int q;
        cin >> n >> q;
        cin >> s;

        vector<vector<int>> queries(q, vector<int> (3));
        for(auto &e : queries) {
            cin >> e[0] >> e[1] >> e[2];
            e[0]--;
            e[1]--;
        }

        vector<bool> ans(q, false);

        string target = "";
        int curr = 0;
        while(target.size() != n) {
            target += to_string(curr);
            curr ^= 1;
        }
        solve(s, target, queries, ans);

        target = "";
        curr = 1;
        while(target.size() != n) {
            target += to_string(curr);
            curr ^= 1;
        }
        solve(s, target, queries, ans);

        for(auto e : ans)
            out(e);
    }
    return 0;
}