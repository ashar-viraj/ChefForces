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
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void update(vector<int> &tree, int start, int end, int idx, int val, int treeNode)
{
    if (start == end)
    {
        tree[treeNode] = val;
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid)
        update(tree, start, mid, idx, val, treeNode * 2);
    else
        update(tree, mid + 1, end, idx, val, treeNode * 2 + 1);

    tree[treeNode] = max(tree[treeNode * 2], tree[treeNode * 2 + 1]);
}

int query(vector<int> &tree, int start, int end, int left, int right, int treeNode)
{
    // left....start..end....right
    if (left <= start && end <= right)
    {
        return tree[treeNode];
    }
    // start..end....left..right
    // left..right....start..end
    else if (end < left || right < start)
    {
        return 0;
    }
    else
    {
        int mid = (start + end) / 2;
        int leftAns = query(tree, start, mid, left, right, treeNode * 2);
        int rightAns = query(tree, mid + 1, end, left, right, treeNode * 2 + 1);

        return max(leftAns, rightAns);
    }
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> h(n), a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        h[i]--;
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> tree(n * 4, 0), dp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int largestSum = query(tree, 0, n - 1, 0, h[i] - 1, 1);
        dp[i] = a[i] + largestSum;
        update(tree, 0, n - 1, h[i], dp[i], 1);
    }

    int ans = dp[0];
    for (auto e : dp)
        ans = max(ans, e);

    cout << ans << endl;

    return 0;
}