// Educational Codeforces Round 101 (Rated for Div. 2)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, j, n, m, temp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> r, b;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            r.push_back(temp);
        }
        cin >> m;
        for (i = 0; i < m; i++)
        {
            cin >> temp;
            b.push_back(temp);
        }
        int sumr = 0, sumb = 0, temp = 0;
        i = 0;
        j = 0;
        for (i = 0; i < n; i++)
        {
            temp += r[i];
            if (temp > sumr)
            {
                sumr = temp;
            }
        }
        temp = 0;
        for (i = 0; i < m; i++)
        {
            temp += b[i];
            if (temp > sumb)
            {
                sumb = temp;
            }
        }
        cout << sumb + sumr << "\n";
    }
    return 0;
}