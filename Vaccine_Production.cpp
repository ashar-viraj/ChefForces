// December Challenge 2020 Division 2
#include <bits/stdc++.h>
using namespace std;

int vaccineProduction(int d1, int v1, int d2, int v2, int p)
{
    int count = 0, days = 0;
    while (count < p)
    {
        days++;
        if (days >= d1)
        {
            count += v1;
        }
        if (days >= d2)
        {
            count += v2;
        }
    }
    return days;
}

int main()
{
    int d1, v1, d2, v2, p;
    cin >> d1 >> v1 >> d2 >> v2 >> p;
    cout << vaccineProduction(d1, v1, d2, v2, p) << endl;
    return 0;
}