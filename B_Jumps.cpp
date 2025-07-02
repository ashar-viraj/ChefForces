// Educational Codeforces Round 99 (Rated for Div. 2)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, i, N, up, jump, diff, naturalSum;
    cin >> T;
    while (T--)
    {
        cin >> N;
        if (N == 2)
        {
            cout << 3 << endl;
            continue;
        }
        else if (N == 4)
        {
            cout << 3 << endl;
            continue;
        }
        else if (N == 5)
        {
            cout << 4 << endl;
            continue;
        }
        up = 0;
        for (i = 1;; i++)
        {
            if ((i * (i + 1)) / 2 >= N)
            {
                up = i;
                break;
            }
        }
        naturalSum = up * (up + 1) / 2;
        diff = naturalSum - N;
        if (diff == 1)
        {
            jump = up + 1;
        }
        else
        {
            jump = up;
        }
        cout << jump << endl;
    }
    return 0;
}