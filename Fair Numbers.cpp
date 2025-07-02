// Codeforces Round #692 (Div. 2, based on Technocup 2021 Elimination Round 3)
#include <bits/stdc++.h>
using namespace std;

long long int fairNumbers(long long int n)
{
    int i, tempi;
    bool a[10] = {false};
    char tempc;
    long long int tempn = n;
    bool found;
    string temps = to_string(n);
    for (i = 0; i < temps.size(); i++)
    {
        a[(int)temps[i] - 48] = true;
    }
    while (true)
    {
        // cout << "number : " << tempn << "\n";
        found = true;
        for (i = 1; i < 10; i++)
        {
            if (a[i] & tempn % i != 0)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return tempn;
        }
        else
        {
            tempn++;
            memset(a, false, sizeof(a));
            string temps = to_string(tempn);
            for (i = 0; i < temps.size(); i++)
            {
                a[(int)temps[i] - 48] = true;
            }
        }
    }
}

int main()
{
    int t;
    long long int n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << fairNumbers(n) << endl;
    }
    return 0;
}