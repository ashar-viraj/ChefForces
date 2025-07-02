// Codeforces Round #692 (Div. 2, based on Technocup 2021 Elimination Round 3)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, l;
    string s;
    cin >> t;
    while (t--)
    {
        int count = 0;
        cin >> l >> s;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ')')
            {
                break;
            }
            count++;
        }
        if (count > s.size() / 2)
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