#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, N, i, j, count;
    int num, den, gcd;
    count = 0;
    cin >> N;
    for (i = 1; i <= N; i++)
    {
        for (j = i; j <= N; j++)
        {
            num = i * (j + 1);
            den = (i + 1) * j;
            gcd = __gcd(num, den);
            num /= gcd;
            den /= gcd;
            if (num + 1 == den)
                count++;
        }
    }
    cout << count << "\n";
    return 0;
}