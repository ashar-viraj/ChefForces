//  December Lunchtime 2020 Division 2
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
        int fre[26];
        memset(fre, 0, sizeof(fre));
        for (i = 0; i < s.size(); i++)
        {
            fre[s[i] - 97]++;
        }
        // for (i = 0; i < 26; i++)
        // {
        //     if (fre[i])
        //         cout << fre[i] << char(i + 97) << "\n";
        // }
        int even = 0, odd = 0;
        for (i = 0; i < 26; i++)
        {
            even += fre[i] / 2;
            odd += fre[i] % 2;
        }
        if (odd == even)
        {
            cout << odd << "\n";
        }
        else if (odd > even)
        {
            cout << even << "\n";
        }
        else
        {
            int temp = even - odd;
            cout << odd + ((temp * 2) / 3) << "\n";
        }
    }
    return 0;
}
