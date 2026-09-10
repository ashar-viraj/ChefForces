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

bool solve(vector<int> v, int startIdx, int val, map<int, int> freq)
{
    int i = startIdx, j = 0, swaps = 0;
    queue<int> idx;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == val && (i < startIdx || i >= startIdx + freq[val]))
            idx.push(i);
    }

    for (int i = startIdx; i < startIdx + freq[val] && i < v.size(); i++)
    {
        if (v[i] != val)
        {
            swaps++;
            swap(v[i], v[idx.front()]);
        }
    }

    if (swaps > 1)
        return false;

    map<int, int> firstIdx, lastIdx;
    for (int i = 0; i < v.size(); i++)
    {
        if (!firstIdx.count(v[i]))
            firstIdx[v[i]] = i;
        lastIdx[v[i]] = i;
    }

    for (auto e : v)
    {
        if (freq[e] != (lastIdx[e] - firstIdx[e] + 1))
            return false;
    }

    return true;
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
        vector<int> v(n);
        map<int, int> freq, firstIdx, lastIdx;
        int val = -1;
        for (auto &e : v)
        {
            cin >> e;
            freq[e]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (!firstIdx.count(v[i]))
                firstIdx[v[i]] = i;
            lastIdx[v[i]] = i;
        }

        for (auto e : v)
        {
            if (freq[e] != (lastIdx[e] - firstIdx[e] + 1))
            {
                val = e;
                break;
            }
        }


        out((val == -1) ||
            (val != -1 && (solve(v, firstIdx[val] - 1, val, freq) ||
                            solve(v, firstIdx[val], val, freq) ||
                            solve(v, firstIdx[val] + 1, val, freq) ||
                            solve(v, lastIdx[val] - freq[val] + 1, val, freq) ||
                            solve(v, lastIdx[val] - freq[val] + 2, val, freq) ||
                            solve(v, lastIdx[val] - freq[val], val, freq)))
            );
    }
    return 0;
}