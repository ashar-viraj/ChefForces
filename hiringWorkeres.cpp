#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

//K team
//X days
void findTwoSmallestPrimesFactors(int K, int X)
{
    int count = 0, temp1 = 1, temp = 0, i;
    for (i = 2; i < X; i++)
    {
        if (X % i != 0)
        {
            continue;
        }
        if (isprime(i))
        {
            temp += i;
            temp1 *= i;
            count++;
        }
    }
    if (count < K && temp1 == X)
    {
        cout << temp + (K - count) << endl;
    }
    else
    {
        cout << X + (K - 1) << endl;
    }
}

int main()
{
    int T, i, K, X;
    cin >> T;
    while (T--)
    {
        cin >> K >> X;
        findTwoSmallestPrimesFactors(K, X);
    }
    return 0;
}