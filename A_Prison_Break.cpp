#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, i, temp, max;
    int n, m, r, c;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> r >> c;
        temp = abs(r - 1) + abs(c - 1);
        max = temp;
        cout << temp << " " << max << endl;

        temp = abs(r - 1) + abs(c - m);
        if (temp > max)
            max = temp;
        cout << temp << " " << max << endl;

        temp = abs(r - n) + abs(c - 1);
        if (temp > max)
            max = temp;
        cout << temp << " " << max << endl;

        temp = abs(r - n) + abs(c - m);
        if (temp > max)
            max = temp;
        cout << temp << " " << max << endl;

        cout << max << endl;
    }
    return 0;
}