#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, N, bur1, bur2;
    cin >> t;
    while (t--)
    {
        cin >> N;
        int dishes[N];
        bur1 = 0;
        bur2 = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> dishes[i];
        }
        for (int i = N - 1; i >= 0; i--)
        {
            if (bur1 < bur2)
            {
                bur1 += dishes[i];
            }
            else
            {
                bur2 += dishes[i];
            }
        }
        if (bur1 > bur2)
        {
            cout << bur1;
        }
        else
        {
            cout << bur2;
        }
    }
    return 0;
}