#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (i = a; i < b; i++)
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, px, py, itemp;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> px >> py;
        cin >> s;
        int U = 0, D = 0, L = 0, R = 0;
        rep(i, 0, s.size())
        {
            if (s[i] == 'U')
                U++;
            else if (s[i] == 'D')
                D++;
            else if (s[i] == 'R')
                R++;
            else
                L++;
        }
        int x = R-L, y = U-D;
        bool possible = true;
        // x += L;
        // y += D;
        if (x == px && y == py)
        {
            possible = true;
        }
        else
        {
            int requiredHorizantal, requiredVertical;
            if (y > py)
            {
                requiredVertical = y - py;
                if (U < requiredVertical)
                    possible = false;
            }
            else
            {
                requiredVertical = py - y;
                if (D < requiredVertical)
                    possible = false;
            }
            if (x > px)
            {
                requiredHorizantal = x - px;
                if (R < requiredHorizantal)
                    possible = false;
            }
            else
            {
                requiredHorizantal = px - x;
                if (L < requiredHorizantal)
                    possible = false;
            }
        }
        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}