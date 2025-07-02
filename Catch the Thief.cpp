//December Cook-Off 2020
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t, i, x, y, k, n;
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> k >> n;
        if ((x - y) % 2 != 0)
        {
            cout << "No\n";
            continue;
        }
        if ((x - y) % (2 * k) == 0)
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