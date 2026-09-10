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

void solve(int k, int x, int y, string &finalAns, int &dis) {
    string ans = "";
    while(k > 0) {
        if(y >= x && y >= k) {
            ans += "Y";
            y -= k;
            k--;
        } else if(x >= k) {
            ans += "X";
            x -= k;
            k--;
        } else {
            return;
        }
    }

    if((x * x + y * y) < dis && k == 0)
    {
        finalAns = ans;
        dis = x*x + y*y;
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
        int x, y;
        cin >> x >> y;

        int k = 0, sum = 0;
        while((sum + k + 1) <= (x + y)) {
            k++;
            sum += k;
        }

        string ans = "";
        int dis = LONG_MAX;
        solve(k, x, y, ans, dis);
        solve(k-1, x, y, ans, dis);
        solve(k-2, x, y, ans, dis);
        solve(k-3, x, y, ans, dis);

        cout << ans << endl;
    }
    return 0;
}