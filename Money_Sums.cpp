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
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    unordered_set<int> ans;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        unordered_set<int> newAns;
        for (auto e : ans)
            newAns.insert(e + val);
        newAns.insert(val);

        for(auto e : newAns)
            ans.insert(e);
    }

    vector<int> v;
    for (auto e : ans)
        v.push_back(e);
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto e : v)
        cout << e << ' ';

    return 0;
}