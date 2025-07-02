// December Challenge 2020 Division 2
#include <bits/stdc++.h>
using namespace std;

long long int evenPairSum(long long int A, long long int B)
{
    // cout << "Even = " << ((A / 2) * (B / 2)) << endl;
    // cout << "Odd = " << ((A + 1) / 2 * (B + 1) / 2) << endl;
    return ((A / 2) * (B / 2)) + (((A + 1) / 2) * ((B + 1) / 2));
}

int main()
{
    int T;
    long long int A, B;
    cin >> T;
    while (T--)
    {
        cin >> A >> B;
        cout << evenPairSum(A, B) << endl;
    }
    return 0;
}