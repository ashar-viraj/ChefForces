#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t, i, n, k, temp;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        while (true)
        {
            if (k <= 0)
            {
                break;
            }
            if (n % 10 != 0)
            {
                if (k > n % 10)
                {
                    temp = n % 10;
                    k -= n % 10;
                    n -= temp;
                }
                else
                {
                    n -= k;
                    k = 0;
                }
            }
            else
            {
                k--;
                n /= 10;
            }
        }
        cout << n << endl;
    }
    return 0;
}