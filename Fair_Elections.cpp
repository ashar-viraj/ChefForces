//  January Challenge 2021 Division 2
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, m, temp, j;
    cin >> t;
    while (t--)
    {
        int t1 = 0, t2 = 0;
        cin >> n >> m;
        vector<int> joja, jajo;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            t1 += temp;
            joja.push_back(temp);
        }
        for (i = 0; i < m; i++)
        {
            cin >> temp;
            t2 += temp;
            jajo.push_back(temp);
        }
        sort(joja.begin(), joja.end());
        sort(jajo.begin(), jajo.end());
        int count = 0;
        i = 0;
        j = m - 1;
        while (t1 <= t2 && i < n && j >= 0)
        {
            count++;
            t1 += (jajo[j] - joja[i]);
            t2 += (joja[i] - jajo[j]);
            i++;
            j--;
        }
        if (i == n)
        {
            i--;
        }
        if (t1 <= t2 || i >= n || j < 0)
        {
            cout << "-1\n";
        }
        else
        {
            cout << count << "\n";
        }
    }
    return 0;
}