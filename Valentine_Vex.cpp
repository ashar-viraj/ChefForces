#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

pair<int, int> solve(vector<int> &o, int i, int on, vector<int> &e, int j, int en, bool aChance, bool aParity, bool bparity)
{
    pair<int, int> ans = {0, 0};

    if (aChance)
    {
        if (aParity)
        {
            if (i >= 0)
            {
                ans = solve(o, i - 1, on, e, j, en, !aChance, !aParity, bparity);
                ans.first += o[i];
            }
            else
            {
                ans = solve(o, i, on, e, j, en, !aChance, aParity, bparity);
            }
        }
        else
        {
            if (j >= 0)
            {
                ans = solve(o, i, on, e, j - 1, en, !aChance, !aParity, bparity);
                ans.first += e[j];
            }
            else
            {
                ans = solve(o, i, on, e, j, en, !aChance, aParity, bparity);
            }
        }
    }
    else
    {
        if (bparity)
        {
            if (i >= 0)
            {
                ans = solve(o, i - 1, on, e, j, en, !aChance, aParity, !bparity);
                ans.second += o[i];
            }
            else
            {
                ans = solve(o, i, on, e, j, en, !aChance, aParity, bparity);
            }
        }
        else
        {
            if (j >= 0)
            {
                ans = solve(o, i, on, e, j - 1, en, !aChance, aParity, !bparity);
                ans.second += e[j];
            }
            else
            {
                ans = solve(o, i, on, e, j, en, !aChance, aParity, bparity);
            }
        }
    }

    // pair<int, int> ans = {aSum, bSum};
    // if (aChance)
    // {
    //     if (aParity)
    //     {
    //         ans.first = solve(o, i - 1, on, e, j, en, !aChance, !aParity, bparity, o[i], bSum) + o[i];
    //     }
    //     else
    //     {
    //         ans.first = solve(o, i, on, e, j - 1, en, !aChance, !aParity, bparity, aSum, bSum) + e[j];
    //     }
    // }
    // else
    // {
    //     if (bparity)
    //     {
    //         ans.second = solve(o, i - 1, on, e, j, en, !aChance, aParity, !bparity, aSum, bSum) + o[i];
    //     }

    //     else
    //     {
    //         ans.second = solve(o, i, on, e, j + 1, en, !aChance, aParity, !bparity, aSum, bSum) + e[j];
    //     }
    // }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> v(n);
        rep(i, 0, n) cin >> v[i];

        vector<int> o, e;
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2)
                o.push_back(v[i]);
            else
                e.push_back(v[i]);
        }

        int on = o.size() - 1, en = e.size() - 1;
        bool aparity, bparity, aover, bover, achance;

        aparity = 1, bparity = 1, aover = false, bover = false;
        int sum1 = 0, sum2 = 0, ans = 0, bests1 = 0, bests1 = 0;
        while (!aover && !bover && on >= 0 && en >= 0)
        {
            if (achance)
            {
                if (aparity)
                {
                    sum1 += o[on];
                    on--;
                    aparity
                }
            }
            else
            {
            }
        }
    }
    return 0;
}