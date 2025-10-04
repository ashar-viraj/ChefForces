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

int32_t main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (auto &e : v)
        cin >> e;

    int ans = 0, i = 0, j = 0;
    set<int> s;
    map<int, int> f;

    while (j < n)
    {
        s.insert(v[j]);
        f[v[j]]++;

        while (s.size() > k)
        {
            f[v[i]]--;
            if (f[v[i]] == 0)
                s.erase(v[i]);
            i++;
        }

        j++;
        ans += j - i;
    }

    cout << ans;

    return 0;
}