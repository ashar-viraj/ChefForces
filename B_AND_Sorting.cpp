#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n' 
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void buildSegTree(int *tree, int *arr, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    buildSegTree(tree, arr, start, mid, treeNode * 2);
    buildSegTree(tree, arr, mid + 1, end, treeNode * 2 + 1);

    tree[treeNode] = tree[treeNode * 2] + tree[treeNode * 2 + 1];
}

void updateSegTree(int *tree, int *arr, int start, int end, int treeNode, int idx, int val)
{
    if (start == end)
    {
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }

    int mid = (start + end) / 2;
    if (idx > mid)
    {
        // right
        updateSegTree(tree, arr, mid + 1, end, treeNode * 2 + 1, idx, val);
    }
    else
    {
        // left
        updateSegTree(tree, arr, start, mid, treeNode * 2, idx, val);
    }

    tree[treeNode] = tree[treeNode * 2] + tree[treeNode * 2 + 1];
}

int fetchQuery(int *tree, int start, int end, int treeNode, int left, int right)
{

    if (right < start || end < left)
    {
        // Completely outside in given range
        return 0;
    }
    else if (start >= left && end <= right)
    {
        // Completely inside given range
        return tree[treeNode];
    }
    else
    {
        // partially inside and partially outsise
        int mid = (start + end) / 2;
        int ans1 = fetchQuery(tree, start, mid, treeNode * 2, left, right);
        int ans2 = fetchQuery(tree, mid + 1, end, treeNode * 2 + 1, left, right);
        return ans1 + ans2;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ans = -1;
        rep(i, 0, n)
        {
            if(v[i] != i)
            {
                if(ans == -1)
                {
                    ans = v[i];
                }
                else
                {
                    ans &= v[i];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}