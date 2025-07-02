#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t, i, n, x;
    bool destroyed;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        destroyed = false;
        long long int arr[n];
        for (i = 0; i < n; i += 2)
        {
            cin >> arr[i];
        }
        for (i = (n % 2 == 0 ? n - 1 : n - 2); i > 0; i -= 2)
        {
            cin >> arr[i];
        }
        int energy = 0;
        for (i = 0; i < n - 1; i += 2)
        {
            if (arr[i] > arr[i + 1])
            {
                energy += arr[i];
            }
            else
            {
                energy += arr[i + 1];
            }
            if (energy >= x)
            {
                cout << "YES\n";
                destroyed = true;
                break;
            }
        }
        if (destroyed)
        {
            continue;
        }
        if (n % 2 != 0)
        {
            energy += arr[n / 2];
        }
        if (energy >= x)
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