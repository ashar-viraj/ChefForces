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

void solve(string s, int k)
{
    string S = s;
    deque<int> idx;
    int i = 0;
    for(auto e : s) {
        if(e == '(') {
            idx.push_back(i);
        } else {
            if(idx.size()) {
                idx.pop_back();
            }
        }
        i++;
    }

    int firstOpen = s.size()-1;
    if(idx.size()) {
        firstOpen = idx.front();
    }
    // cout << firstOpen << endl;

    for(int i = 0; i < s.size() && k > 0; i++) {
        if(i < firstOpen) {
            if(s[i] == '(') {
                s[i] = '1';
                k--;
            }
        } else {
            if(s[i] == ')') {
                s[i] = '1';
                k--;
            }
        }
    }

    // cout << S << endl;
    for(auto e : s)
        cout << (e == '1' ? 1 : 0);
    cout << endl;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int k;
        cin >> n >> k;
        string s;
        cin >> s;
        solve(s, k);
        // cout << ans1 << ' ' << ans2 << ' ';
        // if (ans1 < ans2)
        //     print(s, '(', k);
        // else
        //     print(s, ')', k);
        // stack<int> idx;
        // vector<int> openIdxV, closeIdxV;
        // for(i = 0; i < n; i++) {
        //     char ch;
        //     cin >> ch;
        //     s += ch;
        //     if(ch == '(')
        //         idx.push(i);
        //     else if(!idx.empty()) {
        //         int openIdx = idx.top();
        //         idx.pop();
        //         s[openIdx] = '0';
        //         s[i] = '0';
        //         openIdxV.push_back(openIdx);
        //         closeIdxV.push_back(i);
        //     }
        // }
        // string ans = s;
        // vector<int> consider;
        // if(idx.empty()) {
        //     consider = closeIdxV;
        // } else {
        //     consider = openIdxV;
        // }

        // while(k > 0 && !consider.empty()) {
        //     int idx = consider.back();
        //     consider.pop_back();
        //     ans[idx] = '1';
        //     k--;
        // }

        // for(auto e : ans)
        //     cout << (e == '1' ? 1 : 0);

        // cout << endl;
    }
    return 0;
}