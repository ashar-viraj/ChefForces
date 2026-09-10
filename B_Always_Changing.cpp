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


int getAns(const string &s, char need)
{
    int len = 0;

    for(char e : s)
    {
        if(e == need)
        {
            len++;
            need = (need == '0' ? '1' : '0');
        }
    }

    return len;
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
        cin >> n >> s;

        int zeros = 0;
        for(auto e : s)
            zeros += e == '0';

        int ones = n - zeros, diff = zeros - ones;

        int ans0 = getAns(s, '0');
        int ans1 = getAns(s, '1');

        map<int,int> best;

        best[1] = (ans0 & 1) ? ans0 : ans0 - 1;

        best[-1] = (ans1 & 1) ? ans1 : ans1 - 1;

        int even0 = (ans0 & 1) ? ans0 - 1 : ans0;
        int even1 = (ans1 & 1) ? ans1 - 1 : ans1;
        best[0] = max({0LL, even0, even1});

        int ans = INT_MAX;

        for(auto e : best)
        {
            if(e.second < 0)
                continue;
            if(abs(diff - e.first) <= 1)
                ans = min(ans, n - e.second);
        }

        if(ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}