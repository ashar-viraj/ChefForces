//  January Challenge 2021 Division 2
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, m, itemp, j;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> v;
        for (i = 0; i < n; i++)
        {
            vector<int> vtemp;
            cin >> m;
            for (j = 0; j < m; j++)
            {
                cin >> itemp;
                vtemp.push_back(itemp);
            }
            v.push_back(vtemp);
        }
        if (n == 1)
        {
            int negative = 0, positive = 0;
            for (i = 0; i < v[0].size(); i++)
            {
                if (v[0][i] < 0)
                {
                    negative++;
                }
                else if (v[0][i] > 0)
                {
                    positive++;
                }
            }
            cout << negative * positive << endl;
        }
        else
        {
                }
    }
    return 0;
}