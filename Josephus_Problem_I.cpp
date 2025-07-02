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
    int n;
    cin >> n;
    vector<int> next(n + 1);
    for (int i = 1; i <= n; i++)
        next[i] = i + 1;
    next[n] = 1;

    int curr = 1;
    vector<int> ans;
    while (next[curr] != curr)
    {
        ans.push_back(next[curr]);
        next[curr] = next[next[curr]];
        curr = next[curr];
    }
    ans.push_back(curr);

    for(auto e : ans)
        cout << e << ' ';

    return 0;
}