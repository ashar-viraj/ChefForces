#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'

// A box can only be kept red (never colored blue) if its position is a
// left-to-right maximum of the array. Consider the chosen red positions in
// order p_1 < p_2 < ... with values v_1 < v_2 < ... (this is automatically
// an increasing subsequence). Each red needs (v_i - p_i) blue boxes to cross
// over it before it settles at its final spot, and:
//   - if v_i == p_i, the box never moves: it's a hard divider, and it can
//     only be used if the prefix [1..p_i] is exactly the set {1..p_i}
//     (this always holds automatically for a left-to-right max equal to its
//     own position), which resets the "segment" (positions reset relative
//     to p_i+1 afterwards).
//   - if v_i > p_i, we need at least one blue before it at every point in
//     time, which (after accounting for previously chosen reds in the same
//     segment) means its local rank m must satisfy p_i > m, i.e. the count
//     of already-chosen reds in the segment before it is < p_i - 1 (local).
//   - two chosen reds that end up at literally adjacent array positions
//     force every crossing of one to also cross the other, so they must
//     need the exact same number of crossings, or the later one must be
//     skipped.
// Maximizing the number of reds we can keep (and hence minimizing the blue
// count = n - that) reduces to a single left-to-right greedy scan.

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        int M = 0;
        int segStart = 1;
        int localCount = 0;
        int total = 0;

        bool hasLast = false;
        int lastPos = 0, lastReq = 0;

        for (int i = 1; i <= n; i++)
        {
            int v = p[i];
            if (v <= M)
                continue;
            M = v;

            int req;
            bool feasible;
            if (v == i)
            {
                req = 0;
                feasible = true;
            }
            else
            {
                req = v - i;
                int deadline = i - segStart;
                feasible = (localCount + 1 <= deadline);
            }
            if (!feasible)
                continue;

            bool conflict = hasLast && (i == lastPos + 1) && (lastReq != req);
            if (conflict)
                continue;

            total++;
            if (v == i)
            {
                segStart = i + 1;
                localCount = 0;
            }
            else
            {
                localCount++;
            }
            hasLast = true;
            lastPos = i;
            lastReq = req;
        }

        cout << (n - total) << endl;
    }
    return 0;
}
