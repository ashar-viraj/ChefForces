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

void update(vector<int> &tree, int left, int right, int node, int idx, int val)
{
    if (left == right)
    {
        tree[node] = val;
        return;
    }

    int mid = (left + right) / 2;

    if (idx <= mid)
        update(tree, left, mid, node * 2 + 1, idx, val);
    else
        update(tree, mid + 1, right, node * 2 + 2, idx, val);

    tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
}

int fetch(vector<int> &tree, int left, int right, int start, int end, int node)
{
    if (right < start || end < left)
        return (4ll * 1e9 * 1e5);

    if (start <= left && right <= end)
        return tree[node];

    int mid = (left + right) / 2;
    int leftAns = fetch(tree, left, mid, start, end, node * 2 + 1);
    int rightAns = fetch(tree, mid + 1, right, start, end, node * 2 + 2);

    return min(leftAns, rightAns);
}

int32_t main()
{
    int n, a, b;

    cin >> n >> a >> b;
    vector<int> v(n), tree(8 * n, 4ll * INT_MAX * 1e5);

    for (auto &e : v)
        cin >> e;

    int i = 0, j = 0, sum = 0, ans = 4ll * INT_MIN * 1e5;

    update(tree, 0, n, 0, 0, 0);

    for (int i = 0; i < n; i++)
    {
        // cout << i << " ";
        sum += v[i];

        int minPrefix = fetch(tree, 0, n, i - b + 1, i - a + 1, 0);
        // cout << minPrefix << " ";
        ans = max(ans, sum - minPrefix);
        // cout << ans << endl;
        update(tree, 0, n, 0, i+1, sum);
    }

    cout << ans;

    return 0;
}