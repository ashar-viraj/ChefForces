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

vector<int> solve(vector<int> &v) {
    int maxTwos = 0, maxLen = 0, currTwo = 0, sign = 1, len = 0, ansIdx = 0, currIdx = -1, n = v.size();
    for(auto e : v) {
        currIdx++;
        if(e == 0) {
            len = 0, currTwo = 0, sign = 1;
            continue;
        }

        if(abs(e) == 2)
            currTwo++;
        if(e < 0)
            sign *= -1;
        len++;

        if(sign == 1 && currTwo >= maxTwos) {
            maxTwos = max(maxTwos, currTwo);
            ansIdx = currIdx;
            maxLen = len;
        }

        // cout << currTwo << ' ' << sign << ' ' << len << ' ' << " | " << maxTwos << ' ' << maxLen << " | " << ansIdx << endl;
    }
    // cout << "AnsIdx, maxLen : " << ansIdx << ' ' << maxLen << endl;

    return {ansIdx - maxLen + 1, n - ansIdx - 1, maxTwos};
}

int32_t main()
{
    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> v(n);
        for(auto &e : v)
            cin >> e;

        vector<int> ans1 = solve(v);
        reverse(v.begin(), v.end());
        vector<int> ans2 = solve(v);

        vector<int> ans;
        if(ans1[2] > ans2[2])
            ans = ans1;
        else
            ans = {ans2[1], ans2[0]};

        cout << ans[0] << ' ' << ans[1] << endl;
        // cout << "===========\n";

    }
    return 0;
}