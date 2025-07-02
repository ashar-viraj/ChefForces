//  December Lunchtime 2020 Division 2
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, temp, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int sum = 0;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            sum += temp;
        }
        if (sum % k == 0)
        {
            cout << "0\n";
        }
        else
        {
            cout << "1\n";
        }
    }
    return 0;
}