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

    int t, i, j, n, itemp, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> v(n);
        map<int, int> freq;
        map<int, vector<int>> idx;
        rep(i, 0, n)
        {
            cin >> v[i], freq[v[i]]++, idx[v[i]].push_back(i);
        }
        int count = 0;
        for (auto e : freq)
        {
            count = min(k, e.second);
        }
        count = count / k;
        int ans[n], color = 0;
        memset(ans, 0, sizeof(ans));
        for (auto e : freq)
        {
            for (i = 0; i < k && i < idx[e.first].size(); i++)
            {
                ans[idx[e.first][i]] = (color % k) + 1;
                color++;
            }
        }
        // count of color given coc
        map<int, int> coc;
        int mi = INT_MAX;
        for (auto e : ans)
        {
            if (e == 0)
                continue;
            coc[e]++;
        }
        for (auto e : coc)
        {
            mi = min(mi, e.second);
        }
        rep(i, 0, n)
        {
            if (coc[ans[i]] > mi)
            {
                coc[ans[i]]--;
                ans[i] = 0;
            }
        }
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
2 1 2 3 0 1 3 2 3 1 
1 2 3 4 
1 
1 1 1 0 1 1 1 1 0 0 0 1 0 
2 1 2 2 1 1 1 1 2 1 0 2 2 
1 1 3 2 1 3 3 1 2 2 3 2 1
*/