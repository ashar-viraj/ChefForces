#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n;
    string r, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int rcount = 0, bcount = 0;
        cin >> r >> b;
        for (i = 0; i < n; i++)
        {
            if (r[i] > b[i])
            {
                rcount++;
            }
            else if (r[i] < b[i])
            {
                bcount++;
            }
        }
        if (rcount > bcount)
        {
            cout << "RED\n";
        }
        else if (bcount > rcount)
        {
            cout << "BLUE\n";
        }
        else
        {
            cout << "EQUAL\n";
        }
    }
    return 0;
}