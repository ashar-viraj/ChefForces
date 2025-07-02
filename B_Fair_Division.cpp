// Codeforces Round #693
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n;
    cin >> t;
    while (t--)
    {
        int two = 0, one = 0, temp;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        if (one % 2 != 0)
        {
            cout << "NO\n";
        }
        else if (two % 2 != 0)
        {
            if (one >= 2)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}