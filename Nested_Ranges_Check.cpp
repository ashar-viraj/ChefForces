#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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

bool compare(vector<int> &a, vector<int> &b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    return a[1] > b[1];
}

int32_t main()
{
    ordered_multiset s;
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }

    sort(v.begin(), v.end(), compare);

    vector<int> inside(n, 0), covering(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        inside[v[i][2]] = s.order_of_key(v[i][1] + 1);
        s.insert(v[i][1]);
    }

    sort(v.begin(), v.end(), compare);

    s.clear();

    for (int i = 0; i < n; i++)
    {
        covering[v[i][2]] = (int)s.size() - (int)s.order_of_key(v[i][1]);
        s.insert(v[i][1]);
    }

    for (auto e : inside)
        cout << e << ' ';
    cout << endl;
    for (auto e : covering)
        cout << e << ' ';

    return 0;
}