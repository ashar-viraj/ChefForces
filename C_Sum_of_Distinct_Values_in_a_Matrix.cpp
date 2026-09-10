#include <bits/stdc++.h>
using namespace std;

#define int long long int

int getAns(vector<int> &r, vector<int> &c, int n, int m, int x, int y)
{
    int ans = 0;
    int uniqueN = 0, uniqueM = 0, common = 0;
    int taken = 0;

    int i = x-1, j = y-1;

    while(i >= 0 && j >= 0) {
        if(r[i] == c[j]) {
            if ((uniqueN + uniqueM + common) < (n + m))
            {
                ans += c[j];
                common++;
            }
            i--, j--;
        } else if(r[i] > c[j]) {
            if (uniqueN < n && (uniqueN + uniqueM + common) < (n + m))
            {
                ans += r[i];
                uniqueN++;
            }
            i--;
        } else {
            if (uniqueM < m && (uniqueN + uniqueM + common) < (n + m))
            {
                ans += c[j];
                uniqueM++;
            }
            j--;
        }
    }

    while(i >= 0) {
        if (uniqueN < n && (uniqueN + uniqueM + common) < (n + m))
        {
            ans += r[i];
            uniqueN++;
        }
        i--;
    }

    while(j >= 0) {
        if (uniqueM < m && (uniqueN + uniqueM + common) < (n + m))
        {
            ans += c[j];
            uniqueM++;
        }
        j--;
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int x, y;
        cin >> n >> m >> x >> y;
        vector<int> r(x), c(y);
        for (auto &e : r) cin >> e;
        for (auto &e : c) cin >> e;
        sort(r.begin(), r.end());
        sort(c.begin(), c.end());
        int ans1 = getAns(r, c, n - 1, m, x, y);
        int ans2 = getAns(r, c, n, m - 1, x, y);

        cout << max(ans1, ans2) << endl;
    }
    return 0;
}