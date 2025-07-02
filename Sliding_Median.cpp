#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
#define f first
#define s second
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    ordered_set s;

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto &e : v)
        cin >> e;

    vector<int> ans;

    int i = 0, j = 0;
    while (j < k)
        s.insert(v[j++]);

    ans.push_back(min(*s.find_by_order(k / 2), *s.find_by_order((k - 1) / 2)));

    while (j < n)
    {
        s.erase(s.find_by_order(s.order_of_key(v[i])));
        s.insert(v[j]);
        i++, j++;
        ans.push_back(min(*s.find_by_order(k / 2), *s.find_by_order((k - 1) / 2)));
    }

    for (auto e : ans)
        cout << e << ' ';

    return 0;
}