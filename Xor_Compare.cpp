#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, i, count;
    long long int X, Y, N;
    cin >> T;
    while (T--)
    {
        count = 0;
        cin >> X >> Y >> N;
        for (i = 0; i <= N; i++)
        {
            if ((X ^ i) < (Y ^ i))
            {
                cout << "i = " << i << ", ";
                cout << X << "^" << i << " = " << (X ^ i) << ", " << Y << "^" << i << " = " << (Y ^ i) << "\n";
                count++;
            }
            else
            {
                cout << "False, " << X << "^" << i << " = " << (X ^ i) << ", " << Y << "^" << i << " = " << (Y ^ i) << "\n";
            }
        }
        cout << count << "\n";
    }
    return 0;
}