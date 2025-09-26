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

void update(vector<int> &tree, int left, int right, int idx, int node, int val)
{
    if (left == right)
    {
        (tree[idx] += val) %= MOD;
        return;
    }

    int mid = (left + right) / 2;
    if (node <= mid)
        update(tree, left, mid, idx * 2 + 1, node, val);
    else
        update(tree, mid + 1, right, idx * 2 + 2, node, val);

    tree[idx] = (tree[idx * 2 + 1] + tree[idx * 2 + 2]) % MOD;
}

int fetch(vector<int> &tree, int left, int right, int start, int end, int idx)
{
    if (right < start || end < left)
        return 0;

    if (start <= left && right <= end)
        return tree[idx];

    int mid = (left + right) / 2;

    int ans = (fetch(tree, left, mid, start, end, idx * 2 + 1) +
               fetch(tree, mid + 1, right, start, end, idx * 2 + 2)) %
              MOD;

    return ans;
}

int solve(vector<int> &v, int n)
{
    int ans = 0;

    vector<int> tree(n * 16, 0);

    for (auto e : v)
    {
        int smallAns = (e == 0 ? 0 : fetch(tree, 0, n - 1, 0, e - 1, 0)) + 1;

        (ans += smallAns) %= MOD;
        update(tree, 0, n - 1, 0, e, smallAns);
    }

    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    set<int> s;
    map<int, int> mp;

    vector<int> v(n);
    for (auto &e : v)
    {
        cin >> e;
        s.insert(e);
    }

    int i = 0;
    for (auto e : s)
        mp[e] = i++;

    for (auto &e : v)
        e = mp[e];
    cout << solve(v, n) << endl;

    return 0;
}