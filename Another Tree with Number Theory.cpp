#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int countRemainingTask(map<int, vector<int>> parents, map<int, int> countChildren, int v, int w)
{
    int task = 0;
    if(countChildren[v] == 0)
    {
        return 0;
    }
    else if(w%countChildren[v] == 0)
    {
        for(auto itr = parents[v].begin(); itr != parents[v].end(); itr++)
        {
            task += countRemainingTask(parents, countChildren, *itr, w/countChildren[v]);
        }
    }
    else
    {
        return w;
    }
    return task;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, q, w, v, itemp;
    cin >> n;
    map<int, vector<int>> parents;
    map<int, int> countChildren;
    rep(i, 2, n+1)
    {
        cin >> itemp;
        parents[itemp].push_back(i);
        // parents[itemp][i] = true;
        countChildren[itemp]++;
    }
    cin >> q;
    while (q--)
    {
        cin >> v >> w;
        cout << countRemainingTask(parents, countChildren, v, w) << "\n";
    }

    return 0;
}