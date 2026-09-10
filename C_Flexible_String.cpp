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
    for (int i = 0; i < tree.size(); i++)
    {
        cout << tree[i] << ' ';
        if (((i + 1) & (i + 2)) == 0)
            cout << endl;
    }
}

int getAns(string s, string &t, vector<bool> &taken)
{
    int len = 0, ans = 0, n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (taken[s[i] - 'a'] || s[i] == t[i])
            len++;
        else
            len = 0;
        ans += len;
    }

    return ans;
}

int solve(string &s, string &t, int k, vector<char> unique, int uniqueIdx, vector<bool> &taken, int replaced)
{
    if (replaced == k)
        return getAns(s, t, taken);
    if (uniqueIdx == unique.size())
        return -1;

    int exclude = solve(s, t, k, unique, uniqueIdx + 1, taken, replaced);
    taken[unique[uniqueIdx] - 'a'] = true;
    int include = solve(s, t, k, unique, uniqueIdx + 1, taken, replaced + 1);
    taken[unique[uniqueIdx] - 'a'] = false;

    return max(include, exclude);
}

int32_t main()
{
    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;

        vector<bool> taken(26, false);
        set<char> uniqueS;
        for (auto e : s)
            uniqueS.insert(e);
        vector<char> unique;
        for (auto e : uniqueS)
            unique.push_back(e);

        int ans = solve(s, t, k, unique, 0, taken, 0);

        if (ans != -1)
        {
            cout << ans << endl;
            continue;
        }

        cout << n * (n + 1) / 2 << endl;
    }
    return 0;
}