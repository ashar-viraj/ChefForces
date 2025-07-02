// Codeforces Round #693
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n;
    cin >> t;
    while (t--)
    {
        vector<int> alice, bob;
        int temp;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp % 2 == 0)
            {
                alice.push_back(temp);
            }
            else
            {
                bob.push_back(temp);
            }
        }
        int evenSum = accumulate(alice.begin(), alice.end(), 0);
        int oddSum = accumulate(bob.begin(), bob.end(), 0);
        }
    return 0;
}