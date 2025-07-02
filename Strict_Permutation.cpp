#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        priority_queue<int, vector<int>, greater<int>> smallest;
        vector<pair<int, int>> v(m);
        unordered_map<int, bool> occ;
        rep(i, 0, m)
        {
            cin >> v[i].first >> v[i].second;
            occ[v[i].first] = true;
        }

        // rep(i, 0, m)
        // {
        //     cout << v[i].first << v[i].second << " | ";
        // }
        // cout << endl;

        for (int i = 1; i <= n; i++)
            if (!occ[i])
                smallest.push(i);

        vector<int> ans(n + 1);

        int curr = 1, j = 0;
        bool valid = true;

        sort(v.begin(), v.end(), compare);
        int freqtemp = 0;
        int last = INT_MIN;

        unordered_map<int, bool> isThereInV;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i].second == last)
                v[i].second = v[i + 1].second - 1;
            else
                last = v[i].second;
            isThereInV[v[i].first] = true;
        }

        unordered_map<int, bool> completed;

        for (int i = 1; i <= n; i++)
        {
            if(j < v.size() && completed[v[j].first])
            {
                j++;
                i--;
                continue;
            }
            else if (j < v.size() && (v[j].second < i || v[j].second <= 0))
            {
                valid = false;
                break;
            }
            else if (smallest.empty() || (j < v.size() && v[j].first < smallest.top()))
            {
                ans[i] = v[j].first;
                completed[ans[i]] = true;
                j++;
            }
            else if (j < v.size() && v[j].second == i)
            {
                ans[i] = v[j].first;
                completed[ans[i]] = true;
                j++;
            }
            else if (smallest.size())
            {
                ans[i] = smallest.top();
                completed[ans[i]] = true;
                smallest.pop();
            }
            else
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}