#include <bits/stdc++.h>
using namespace std;

vector<int> Divisors;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i, d, j, temp;

    cout.tie(NULL);
    Divisors.push_back(1);
    Divisors.push_back(2);
    bool found;
    for (j = 1; j <= 5000; j++)
    {
        found = true;
        if (j % 2 == 0 || j % 3 == 0)
        {
            found = false;
            continue;
        }
        for (int i = 5; i * i <= j; i = i + 6)
            if (j % i == 0 || j % (i + 2) == 0)
            {
                found = false;
                break;
            }
        if (found)
        {
            Divisors.push_back(j);
        }
    }

    cin >> t;
    while (t--)
    {
        cin >> d;
        int s = 1, t = -1, u = -1, v = -1;
        for (i = 1; i < Divisors.size(); i++)
        {
            if (s != -1 && t != -1 && u != -1 && v != -1)
            {
                break;
            }
            if (t == -1)
            {
                if (Divisors[i] - s >= d)
                {
                    t = Divisors[i];
                }
            }
            else if (u == -1)
            {
                if (Divisors[i] - t >= d)
                {
                    u = Divisors[i];
                }
            }
            else
            {
                if (Divisors[i] - u >= d)
                {
                    v = Divisors[i];
                }
            }
        }
        cout << s * t * u * v << "\n";
    }
    return 0;
}