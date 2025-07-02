#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    cin >> t;
    while (t--)
    {
        cin >> n;  
        vector<int> v(n + 1);
        map<int, int> freq;
        map<int, vector<int>> idx;
        vector<pair<int, int>> ans;
        v.push_back(-1);
        rep(i, 1, n + 1)
        {
            cin >> v[i];
            freq[v[i]]++;
            idx[v[i]].push_back(i);
        }
        if (idx.size() == 1)
        {
            cout << "NO\n";
            continue;
        }
        int min = LONG_LONG_MAX, minvalue = LONG_LONG_MAX;
        for (auto e : freq)
        {
            if (e.second < minvalue)
            {
                min = e.first;
                minvalue = e.second;
            }
        }
        auto itr = idx[min].begin();
        for (auto e : idx)
        {
            if (e.first == min)
            {
                continue;
            }
            for (auto q : e.second)
            {
                ans.push_back(make_pair(*itr, q));
            }
        }
        i = 0;
        int a = ans[0].second;
        for (auto e : idx[min])
        {
            if(!i++)
                continue;
            ans.push_back(make_pair(e, a));
        }
        cout << "YES\n";
        for (auto e : ans)
        {
            cout << e.first << " " << e.second << "\n";
        }
    }
    return 0;
}