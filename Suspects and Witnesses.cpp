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

void createChain(int curr, unordered_map<int, int> &freq, map<int, int> &pointing)
{
    if (curr == 0 || freq[curr] == 2)
        return;

    freq[curr]++;
    createChain(pointing[curr], freq, pointing);
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
        cout << "Case #" << tc << ": ";
        int k;
        cin >> n >> m >> k;

        if (k == 1)
        {
            unordered_map<int, bool> isPointed, pointing;
            for (int i = 0; i < m; i++)
            {
                int a, b;
                cin >> a >> b;
                isPointed[b] = true;
                pointing[a] = true;
            }
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                if (!isPointed[i])
                    continue;
                ans++;
            }
            cout << ans << endl;
        }
        else
        {
            map<int, int> isPointed, pointing, parent;
            unordered_map<int, int> freq;
            unordered_map<int, bool> visited;
            for (int i = 0; i < m; i++)
            {
                int a, b;
                cin >> a >> b;
                pointing[a] = b;
                parent[b] = a;
            }

            vector<int> smallgroups;
            for (int i = 1; i <= n; i++)
            {
                if (freq[i] == 0)
                {
                    createChain(i, freq, pointing);
                    smallgroups.push_back(i);
                }
            }
            vector<int> groups;
            unordered_map<int, int> parvisited;
            for (int i = 1; i <= n; i++)
            {

                int node = i;
                if (parvisited[node] != 0)
                    continue;
                parvisited[node] = 1;
                while (parent[node] != 0 && parvisited[node] < 2)
                {
                    node = parent[node];
                    parvisited[node]++;
                }
                if (parvisited[node] == 1)
                    groups.push_back(node);
            }

            int ans = 0;

            vector<vector<pair<int, int>>> newGroups;
            for (int i = 0; i < groups.size(); i++)
            {

                int node = pointing[groups[i]];
                unordered_map<int, bool> visited;
                int N = newGroups.size();
                newGroups.push_back({{node, freq[node]}});
                while (!visited[node])
                {
                    newGroups[N].push_back({node, freq[node]});
                    visited[node] = true;
                    node = pointing[node];
                }
                reverse(newGroups[N].begin(), newGroups[N].end());
            }
 

            for(int i = 0; i < newGroups.size(); i++)
            {
                int K = k;

                int j = 0, N = newGroups[i].size();
                while(j < newGroups[i].size() && newGroups[i][j].second == 2)
                {
                    cout << newGroups[i][j].first << ' ' << newGroups[i][j].second << endl;
                    ans++;
                    j++;
                }
                int remain = N - j;

                if(remain > k)
                {
                    ans += (remain - k);
                }
            }
            cout << "ok\n";
            cout << "parsize : " << newGroups.size() << ' ' << newGroups[0].size() << ' ' << newGroups[0][0].first << ' ' << newGroups[0][0].second << endl;
            continue;

            /*
            for (int i = 0; i < groups.size(); i++)
            {

                int curr = groups[i];

                int K = k;
                while (K && !visited[curr] && freq[curr] == 1)
                {
                    visited[curr] = true;
                    curr = pointing[curr];
                    K--;
                }
                while (!visited[curr])
                {
                    ans++;
                    curr = pointing[curr];
                    visited[curr] = true;
                }
            }
            */
            cout << ans << endl;
        }
    }
    return 0;
}