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

    int t, i, j, n, itemp, l, r;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n >> l >> r;
        vector<int> rl, rr; //remain left/right
        map<int, int> rfreq, lfreq;
        map<int, bool> rp, lp; //right/left present
        rep(i, 0, l)
        {
            cin >> itemp;
            lfreq[itemp]++;
            lp[itemp] = true;
        }
        rep(i, 0, r)
        {
            cin >> itemp;
            rfreq[itemp]++;
            rp[itemp] = true;
        }
        int remove;
        for (auto e : lfreq)
        {
            if (rp[e.first])
            {
                remove = min(rfreq[e.first], lfreq[e.first]);
                rfreq[e.first] -= remove;
                lfreq[e.first] -= remove;
            }
        }
        int ans = 0, rls = 0, rrs = 0, oddCount = 0;
        for (auto e : lfreq)
            rl.push_back(e.second), rls += e.second;
        for (auto e : rfreq)
            rr.push_back(e.second), rrs += e.second;
        sort(rl.begin(), rl.end()), sort(rr.begin(), rr.end());
        if (rls == rrs)
            ans = rls;
        else if (rls > rrs)
        {
            for (auto e : rl)
            {
                if (e % 2)
                    oddCount++;
            }
            ans += rrs;
            int evenCount = rls - oddCount;
            if (oddCount <= rrs)
            {
                evenCount -= (rrs - oddCount);
                ans += evenCount / 2;
            }
            else
            {
                ans += evenCount / 2 + (oddCount - rrs);
            }
        }
        else
        {
            for (auto e : rr)
            {
                if (e % 2)
                    oddCount++;
            }
            ans += rls;
            int evenCount = rrs - oddCount;
            if (oddCount <= rls)
            {
                evenCount -= (rls - oddCount);
                ans += evenCount / 2;
            }
            else
            {
                ans += evenCount / 2 + (oddCount - rls);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
3 3 5 5 5
7 7 7 7 8 8 1 1 1 1 1 2 4

2 3             5
1 1 2 4 5       13
1 1 1 2 3        9

2 3
1 1 1 2   4 4
*/

/*
3 3 5 5 5
1 2 4 6 7 8 9 10 11 12 13 14 15 16

2 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/

/*
2 3
9

2 3
1 2 10

3 3
9    

3 3
1 9  (2)
*/