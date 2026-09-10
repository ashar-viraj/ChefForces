#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 998244353
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

const int MAX = 2e6 + 5;

int fact[MAX], invFact[MAX];

int binpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = 1;

    for (int i = 1; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    invFact[MAX - 1] = binpow(fact[MAX - 1], MOD - 2);

    for (int i = MAX - 2; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

int nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        string s;
        cin >> n >> s;
        int freq[2] = {0}, grp[2] = {0};
        char curr = ' ';
        for(auto e : s) {
            if(e == curr) {
                freq[curr - '0']++;
            }
            else {
                curr = e;
                grp[curr - '0']++;
            }
        }
        if(grp[0] == 0 || grp[1] == 0) {
            cout << "1\n";
            continue;
        }

        int ans = (nCr(freq[0] + grp[0] - 1, grp[0] - 1) * nCr(freq[1] + grp[1] - 1, grp[1] - 1)) % MOD;
        cout << ans << endl;
    }
    return 0;
}