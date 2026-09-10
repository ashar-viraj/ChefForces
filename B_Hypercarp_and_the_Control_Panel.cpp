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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> a(n);

        for (auto &e : a)
            cin >> e;

        vector<vector<int>> v;
        int len = 0, curr = a[0];
        for (auto e : a)
        {
            if (e == curr)
                len++;
            else
            {
                v.push_back({curr, len});
                len = 1;
                curr = e;
            }
        }

        v.push_back({curr, len});

        bool isTwoAdj = false;
        for (int i = 1; i < v.size(); i++)
            if (v[i][1] > 1 && v[i - 1][1] > 1)
                isTwoAdj = true;

        if (isTwoAdj)
        {
            cout << v.size() + 2 << endl;
            continue;
        }

        if (v.size() == 1)
        {
            cout << "1\n";
            continue;
        }
        bool canSwap = false;
        for (int i = 0; i < v.size(); i++)
        {
            if(i == 1 && v[i][1] != 1)
                canSwap = true;
            if(i == v.size() - 2 && v[i][1] != 1)
                canSwap = true;
            if(v[i][1] == 1)
                continue;
            if (i - 2 >= 0 && v[i - 2][0] != v[i][0])
                canSwap = true;
            if (i + 2 < v.size() && v[i + 2][0] != v[i][0])
                canSwap = true;
        }
        cout << v.size() + canSwap << endl;
    }
    return 0;
}