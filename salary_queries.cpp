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

struct Query {
    char type;
    int a, b;
};

void update (vector<int> &tree, int idx, int delta) {
    while(idx < tree.size()) {
        tree[idx] += delta;
        idx += (idx & -idx);
    }
}

int query(vector<int> &tree, int idx) {
    int ans = 0;
    while(idx > 0) {
        ans += tree[idx];
        idx -= (idx & -idx);
    }

    return ans;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> all;
    for(auto &e : v) {
        cin >> e;
        all.push_back(e);
    }

    vector<Query> q(m);

    for(auto &e : q) {
        cin >> e.type >> e.a >> e.b;
        if(e.type == '?')
            all.push_back(e.a);
        all.push_back(e.b);
    }
    sort(all.begin(), all.end());
    vector<int> unique = {all[0]};
    for(int i = 1; i < all.size(); i++) if(all[i] != all[i-1]) unique.push_back(all[i]);

    for(auto &e : v) {
        e = lower_bound(unique.begin(), unique.end(), e) - unique.begin() + 1;
    }
    for(auto &e : q) {
        if(e.type == '?')
            e.a = lower_bound(unique.begin(), unique.end(), e.a) - unique.begin() + 1;
        e.b = lower_bound(unique.begin(), unique.end(), e.b) - unique.begin() + 1;
    }

    int us = all.size();
    vector<int> tree(us+3, 0);

    for(auto &e : v)
        update(tree, e, 1);

    for(auto &e : q) {
        if(e.type == '?') {
            int ans = query(tree, e.b) - query(tree, e.a - 1);
            cout << ans << endl;
        } else {
            int vIdx = e.a - 1;
            update(tree, v[vIdx], -1);
            v[vIdx] = e.b;
            update(tree, v[vIdx], 1);
        }
    }

    return 0;
}