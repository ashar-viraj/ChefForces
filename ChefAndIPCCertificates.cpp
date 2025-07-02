#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, m, k;
    cin >> n >> m >> k;
    int a[n][m + k], count = 0, temp = 0;
    bool valid;
    for (int i = 0; i < n; i++)
    {
        temp = 0;
        valid = true;
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
            temp += a[i][j];
        }
        if (temp < m)
            valid = false;
        cin >> temp;
        if (temp > 10)
            valid = false;
        if (valid)
            count++;
    }
    cout << count << endl;
    return 0;
}