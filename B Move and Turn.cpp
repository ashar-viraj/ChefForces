#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << pow(((n / 2) + 1), 2) << "\n";
    }
    else
    {
        cout << 2 * ((n / 2) + 1) * ((n / 2) + 2) << "\n";
    }
    return 0;
}