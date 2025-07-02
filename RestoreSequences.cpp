#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int a[size];
        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }
        vector<int> final;
        final.push_back(2);
        int count = 1;
        bool flag = true;
        for (int i = 3; count != size; i = i + 2)
        {
            flag = true;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                count++;
                final.push_back(i);
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != i + 1)
            {
                final[i] = final[arr[i] - 1];
            }
        }
        for (auto it = final.begin(); it != final.end(); it++)
        {
            cout << *it << "  ";
        }
    }
    return 0;
}