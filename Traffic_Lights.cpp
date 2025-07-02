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

int removeLight(vector<int> &v, int street, vector<int> &prevIdx, vector<int> &nextIdx, um<int, int> &idx)
{
    int id = idx[street];
    int prev = prevIdx[id], next = nextIdx[id];
    nextIdx[prev] = next;
    prevIdx[next] = prev;

    return v[next] - v[prev];
}

int32_t main()
{
    int x, n;
    cin >> x >> n;

    vector<int> v, ans(n, 0), inp(n), nextIdx(n+2), prevIdx(n+2);
    int maxLen = 0;
    um<int, int> idx;
    v.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
        v.push_back(inp[i]);
    }
    v.push_back(x);

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        idx[v[i]] = i;
        prevIdx[i] = i - 1;
        nextIdx[i] = i + 1;
    }

    for (int i = 1; i < v.size(); i++)
        maxLen = max(maxLen, v[i] - v[i - 1]);

    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = maxLen;
        maxLen = max(maxLen, removeLight(v, inp[i], prevIdx, nextIdx, idx));
    }

    for (auto e : ans)
        cout << e << ' ';

    return 0;
}