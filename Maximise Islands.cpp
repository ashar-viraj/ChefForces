#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, m, d, j;
    string stemp;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<string> s;
        for (i = 0; i < n; i++)
        {
            cin >> stemp;
            s.push_back(stemp);
        }
        int min = INT_MAX, count = 0, minTemp = 0;
        char ch = '*';
        for (i = 0; i < n; i++)
        {
            count = i;
            for (j = 0; j < m; j++)
            {
                // cout << s[i][j] << " " << ch << ", ";
                if (count % 2)
                {
                    ch = '*';
                }
                else
                {
                    ch = '.';
                }
                if (s[i][j] != ch)
                {
                    minTemp++;
                }
                count++;
            }
            // cout << "\n";
        }
        if (min > minTemp)
        {
            min = minTemp;
        }
        minTemp = 0;
        ch = '.';
        for (i = 0; i < n; i++)
        {
            count = i;
            for (j = 0; j < m; j++)
            {
                // cout << s[i][j] << " " << ch << ", ";
                if (count % 2)
                {
                    ch = '.';
                }
                else
                {
                    ch = '*';
                }
                if (s[i][j] != ch)
                {
                    minTemp++;
                }
                count++;
            }
            // cout << "\n";
        }
        if (min > minTemp)
        {
            min = minTemp;
        }
        cout << min << "\n";
    }
    return 0;
}