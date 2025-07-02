// Educational Codeforces Round 101 (Rated for Div. 2)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n;
    int arr[5] = {2, 4, 16, 256, 65536};

    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> sqrs;
        int divisionStart = n;
        bool lastElementInArr = false;
        cin >> n;
        for (i = 0; i < 5; i++)
        {
            if (arr[i] <= n)
            {
                sqrs.push_back(make_pair(arr[i], arr[i]));
                divisionStart = arr[i];
            }
            else
            {
                divisionStart = arr[i - 1];
                break;
            }
            if (arr[i] == n)
            {
                lastElementInArr = true;
            }
        }
        vector<pair<int, int>> ceilDivisions;
        int count = 0;

        for (i = 3; i < n; i++)
        {
            if (i == 2 || i == 4 || i == 16 || i == 256 || i == 65536)
            {
                continue;
            }
            else
            {
                count++;
                ceilDivisions.push_back(make_pair(i, n));
            }
        }
        if (!lastElementInArr)
        {
            ceilDivisions.push_back(make_pair(n, divisionStart));
            ceilDivisions.push_back(make_pair(n, divisionStart));
            count += 2;
        }
        i = divisionStart;
        // cout << divisionStart << " = divisionStart\n";
        while (i >= 4)
        {
            ceilDivisions.push_back(make_pair(i, sqrt(i)));
            ceilDivisions.push_back(make_pair(i, sqrt(i)));
            i = sqrt(i);
            count += 2;
        }

        /*if (lastElementInArr)
        {
            for (i = 3; i < n; i++)
            {
                if (i == 2 || i == 4 || i == 16 || i == 256 || i == 65536)
                {
                    continue;
                }
                else
                {
                    count++;
                    ceilDivisions.push_back(make_pair(i, n));
                }
            }

            i = n;
            while (i >= 4)
            {
                ceilDivisions.push_back(make_pair(i, sqrt(i)));
                ceilDivisions.push_back(make_pair(i, sqrt(i)));
                i = sqrt(i);
                count += 2;
            }
        }
        else
        {
            for (i = 3; i < n; i++)
            {
                if (i == 2 || i == 4 || i == 16 || i == 256 || i == 65536)
                {
                    continue;
                }
                else
                {
                    count++;
                    ceilDivisions.push_back(make_pair(i, n));
                }
            }

            i = divisionStart;
            while (i >= 4)
            {
                ceilDivisions.push_back(make_pair(i, sqrt(i)));
                ceilDivisions.push_back(make_pair(i, sqrt(i)));
                i = sqrt(i);
                count += 2;
            }
        }*/

        cout << count << "\n";
        for (auto itr = ceilDivisions.begin(); itr != ceilDivisions.end(); itr++)
        {
            cout << itr->first << " " << itr->second << "\n";
        }
    }
    return 0;
}