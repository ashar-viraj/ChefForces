// Codeforces Round #694 (Div. 2)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t, i, itemp, min;
    cin >> t;
    while (t--)
    {
        min = 0;
        int n, x;
        long long int total = 0, t1 = 0;
        cin >> n >> x;
        for (i = 0; i < n; i++)
        {
            long long int y;
            cin >> y;
            total += y;
            t1 += y / x;
            if (y % x)
            {
                t1++;
            }
        }
        long long int other = total / x;
        if (total % x)
        {
            other++;
        }
        cout << other << " " << t1 << "\n";
    }
    return 0;
}