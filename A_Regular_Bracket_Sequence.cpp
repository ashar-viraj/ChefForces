// Educational Codeforces Round 101 (Rated for Div. 2)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (s[0] == ')' || s[s.size() - 1] == '(')
        {
            cout << "NO\n";
            continue;
        }
        int countOB = 0, countCB = 0, countQM = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                countOB++;
            }
            else if (s[i] == ')')
            {
                countCB++;
            }
            else
            {
                countQM++;
            }
        }
        int required_bracket = abs(countOB - countCB);
        if (required_bracket > countQM)
        {
            cout << "NO\n";
        }
        else
        {
            if (abs(required_bracket - countQM) % 2 == 0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}