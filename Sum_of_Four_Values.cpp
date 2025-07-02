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
    int n, x;
    cin >> n >> x;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    unordered_map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(j != i+1 && v[j] == v[j-1])
                continue;
            if (mp[v[i] + v[j]].size() < 8)
                mp[v[i] + v[j]].push_back({i + 1, j + 1});
        }
    }

    vector<int> ans(4, -1);

    for (auto e : mp)
    {
        int req = x - e.first;
        if (mp.find(req) == mp.end())
            continue;
        for (auto id1 : e.second)
        {
            for (auto id2 : mp[req])
            {
                set<int> unique;
                unique.insert(id1.f);
                unique.insert(id1.s);
                unique.insert(id2.f);
                unique.insert(id2.s);
                if (unique.size() == 4)
                {
                    ans.clear();
                    for (auto e : unique)
                        ans.push_back(e);
                }
            }
        }
        if (ans[0] != -1)
            break;
    }

    if(ans[0] == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (auto e : ans)
        cout << e << ' ';
    // cout << endl;
    // for (auto e : ans)
    //     cout << v[e - 1] << ' ';

    return 0;
}