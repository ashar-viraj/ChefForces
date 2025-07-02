#include <bits/stdc++.h>
using namespace std;

int findncr(int n, int r)
{
    long long int ans = 1;

    if (r > n - r)
        r = n - r;

    int i = 0;
    while (i < r)
    {
        ans *= (n - i);
        ans /= (i + 1);
        i++;
    }

    return ans;
}

int fin_sol(int input1, int input2, int input3)
{
    int maxCanBeUsed = input1, start = input2, end = input3;

    int ans = 0, maxAvailable = end - start + 1;
    for (int i = 1; i <= maxCanBeUsed; i++)
    {
        int smallAns = findncr(maxAvailable + i - 1, i);
        ans += smallAns;
    }

    return ans;
}

int main()
{
    cout << fin_sol(1, 4, 5) << endl;
    cout << fin_sol(2, 8, 9);
    return 0;
}