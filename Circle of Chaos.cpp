//December Cook-Off 2020
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t, i, n, m, kill;
    cin >> t;
    bool con; //will continue to check or not
    while (t--)
    {
        kill = 0;
        cin >> n >> m;
        long long int p[m];
        for (i = 0; i < m; i++)
        {
            cin >> p[i];
        }
        sort(p, p + m);
        bool nestedCon;
        con = true;
        while (con)
        {
            nestedCon = false;
            if (m == 1)
            {
                if (p[0] % n != 0)
                {
                    kill++;
                    n--;
                    nestedCon = true;
                }
            }
            else
            {
                for (i = m - 1; i > 0; i--)
                {
                    if (p[i] % n != 0)
                    {
                        kill += p[i] - p[i - 1];
                        n--;
                        nestedCon = true;
                        break;
                    }
                }
            }
            if (!nestedCon)
            {
                con = false;
            }
        }
        cout << kill << "\n";
    }
    return 0;
}