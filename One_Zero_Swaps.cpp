//  December Lunchtime 2020 Division 2
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, countOne1, countOne2;
    string s1, s2;
    cin >> t;
    while (t--)
    {
        countOne1 = 0;
        countOne2 = 0;
        bool possible = true;
        cin >> n;
        cin >> s1 >> s2;
        if (s1 == s2)
        {
            cout << "Yes\n";
            continue;
        }
        for (i = 0; i < n; i++)
        {
            if (s1[i] == '1')
            {
                countOne1++;
            }
            if (s2[i] == '1')
            {
                countOne2++;
            }
            if (countOne1 < countOne2)
            {
                cout << "No\n";
                possible = false;
                break;
            }
        }
        if (!possible)
        {
            continue;
        }
        if (countOne1 == countOne2 && possible)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}

bool found1 = false, flag = true;
for (i = 0; i < .......)
{
    if (str2[i] == '1')
    {
        found1 = true;
    }
    if (str1[i] == '1' && found1)
    {
        cout << "No\n";
        flag = false;
        break;
    }
}
if (flag)
{
    cout << "Yes\n";
}
