//December Cook-Off 2020
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, c1, c0;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (s.size() % 2 != 0)
        {
            cout << "-1\n";
            continue;
        }
        c0 = 0;
        c1 = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                c0++;
            }
            else
            {
                c1++;
            }
        }
        if (c1 == 0 || c0 == 0)
        {
            cout << "-1\n";
            continue;
        }
        cout << abs(c0 - c1) / 2 << "\n";
    }
    return 0;
}