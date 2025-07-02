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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp, q;
    cin >> n >> q;
    vector<pair<int, int>> v(q);
    for (int i = 0; i < q; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector<int> partition;
    int start = -1, end = -1, freq = 0;
    i = 0;
    while (i < q)
    {
        if (start == -1)
        {
            start = v[i].first;
            end = v[i].second;
            i++;
            freq = 1;
        }
        else
        {
            if (v[i].first >= end)
            {
                end = v[i].second;
                freq++;
                i++;
            }
            else
            {
                start = -1;
                end = -1;
                freq = 0;
                partition.push_back(freq);
            }
        }
    }
    if(start != -1)
    {
        partition.push_back(freq);
    }
    int ans = 1;
    for (int i = 0; i < partition.size(); i++)
    {
        int val = partition[i];
        int newVal = 1;
        while (val--)
        {
            newVal = (newVal * 2) % MOD;
        }
        partition[i] = newVal;
    }

    for (auto e : partition)
    {
        ans = (ans * e) % MOD;
    }
    cout << ans << endl;
    return 0;
}