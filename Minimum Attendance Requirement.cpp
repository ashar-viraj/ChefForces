//December Cook-Off 2020
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, count;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        count = 120 - n;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                count++;
        }
        if (count >= 90)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}