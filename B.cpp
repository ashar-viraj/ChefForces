#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define f first
#define s second
#define um unordered_map
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        cin >> n;
        vector<pair<int, int>> v(n);
        priority_queue<int> pq;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
            mp[v[i].first]++;
            pq.push(v[i].first);
            v[i].second = i;
        }
        vector<int> ans(n);
        sort(v.begin(), v.end());
        bool valid = true;
        for (int i = n - 1; i >= 0; i--)
        {
            while (pq.top() > v[i].first * 2)
            {
                pq.pop();
            }
            int temp = -1;
            if (pq.top() == v[i].first && mp[v[i].first] == 1)
            {
                temp = pq.top();
                pq.pop();
            }
            if (pq.empty())
            {
                ans[v[i].second] = -1;
            }
            else
                ans[v[i].second] = pq.top();
            if(temp != -1)
            {
                pq.push(temp);
            }
        }
        for (auto e : ans)
        {
            cout << e << ' ';
        }
        cout << endl;
    }
    return 0;
}