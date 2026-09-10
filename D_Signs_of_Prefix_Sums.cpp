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

int getAns(string &s, int k, int curr, int i, int n, vector<vector<int>> &dp) {
    if(i == n)
        return 1;

    if(abs(curr) > 5)
        return 0;

    if((s[i] == '0' && curr != 0) || (s[i] == '+' && curr <= 0) || (s[i] == '-' && curr >= 0))
        return 0;

    if(dp[i][curr + 5] != -1)
        return dp[i][curr + 5];

    int ans = 0;
    for(int j = -k; j <= k; j++) {
        if(j != 0)
            ans |= getAns(s, k, curr + j, i+1, n, dp);
    }

    return dp[i][curr + 5] = ans;
}

bool solve(string &s, int k) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(11, -1));

    int ans = 0;
    for(int curr = -k; curr <= k; curr++)
        if(curr != 0)
            ans |= getAns(s, k, curr, 0, n, dp);
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        string s;
        cin >> s;

        if(solve(s, 1))
            cout << "1\n";
        else if(solve(s, 2))
            cout << "2\n";
        else if(solve(s, 3))
            cout << "3\n";
        else if(solve(s, 4))
            cout << "4\n";
        else
            cout << "-1\n";
    }
    return 0;
}