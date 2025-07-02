#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, i, j, N, p, k, x, y, time, timeTemp;
    string s;
    cin >> T;
    while (T--)
    {
        time = INT_MAX;
        cin >> N >> p >> k;
        cin >> s;
        cin >> x >> y;
        for (i = p - 1; i < s.size(); i++)
        {
            timeTemp = 0;
            for (j = i; j < s.size(); j += k)
            {
                if (s[j] != 1)
                {
                    timeTemp += x;
                }
            }
            cout << "Value of timeTemp for inserting " << timeTemp << endl;

            timeTemp += (i + 1 - p) * y;
            if (timeTemp < time)
            {
                time = timeTemp;
            }
        }
        cout << time << endl;
    }
    return 0;
}