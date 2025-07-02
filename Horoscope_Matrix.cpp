//  December Lunchtime 2020 Division 2
#include <bits/stdc++.h>
using namespace std;

void horoscopeMatrix(vector<vector<long long int>> hm, long long int n, long long int m)
{
    int q, k, l;
    long long int v;
    cin >> q;
    while (q--)
    {
        cin >> k >> l >> v;
        hm[k][l] = v;
    }
}

int main()
{
    long long int t, i, n, m, j, itemp, tr, k, l;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<long long int>> hm;
        for (i = 0; i < n; i++)
        {
            vector<long long int> vtemp;
            j = m;
            for (j = 0; j < m; j++)
            {
                cin >> itemp;
                vtemp.push_back(itemp);
            }
            hm.push_back(vtemp);
        }
        bool equalElements[n + m - 1];
        memset(equalElements, true, sizeof(equalElements));
        i = 0;
        j = m - 1;
        tr = n + m - 2;
        while (true)
        {
            k = j;
            i = 0;
            j--;
            itemp = hm[i][k];
            while (k < m && i < n)
            {
                if (hm[i][k] != itemp)
                {
                    equalElements[tr] = false;
                    break;
                }
                k++;
                i++;
            }
            tr--;
            j--;
            if (j == 0)
            {
                break;
            }
        }

        i = n - 1;
        j = 0;
        tr = n - 1;
        while (true)
        {
            k = i;
            l = 0;
            i--;
            itemp = hm[k][l];
            while (k < n && l < m)
            {
                if (hm[k][l] != itemp)
                {
                    equalElements[tr] = false;
                    break;
                }
                k++;
                l++;
            }
            tr--;
            i--;
            if ()
        }
    }
    return 0;
}