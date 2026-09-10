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

bool isPoss(vector<int> &v, int n, int k)
{
    vector<bool> valids(n + 2, false), valide(n + 2, false);

    vector<int> freq(n + 1, 0);
    int distinct = 0;

    deque<int> mn, mx;

    for (int j = 0; j < n; j++)
    {
        if (freq[v[j]]++ == 0)
            distinct++;

        while (mn.size() && v[mn.back()] >= v[j])
            mn.pop_back();
        mn.push_back(j);

        while (mx.size() && v[mx.back()] <= v[j])
            mx.pop_back();
        mx.push_back(j);

        if (j >= k)
        {
            int rem = j - k;
            freq[v[rem]]--;
            if (freq[v[rem]] == 0)
                distinct--;

            if (mn.size() && mn.front() == rem)
                mn.pop_front();

            if (mx.size() && mx.front() == rem)
                mx.pop_front();
        }

        if (j >= k - 1)
        {
            int mi = v[mn.front()];
            int ma = v[mx.front()];

            if (distinct == k && ma - mi + 1 == k)
            {
                valids[mi] = true;
                valide[ma] = true;

                if (mi > 1 && valide[mi - 1])
                    return true;

                if (ma < n && valids[ma + 1])
                    return true;
            }
        }
    }

    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> v(n);
        for (auto &e : v)
            cin >> e;
        int ans = 0;
        for (int k = 1; k <= n / 2; k++)
        {
            if (isPoss(v, n, k))
                ans = k;
        }

        cout << ans << endl;
    }
    return 0;
}