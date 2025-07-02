#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (i = a; i < b; i++)
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<int> point1, point2, memories, point;
        rep(i, 0, n)
        {
            cin >> itemp;
            memories.push_back(itemp);
        }
        rep(i, 0, n)
        {
            cin >> itemp;
            point.push_back(itemp);
        }
        rep(i, 0, n)
        {
            if (point[i] % 2)
            {
                point1.push_back(memories[i]);
            }
            else
            {
                point2.push_back(memories[i]);
            }
        }
        // sort(point1.begin(), point1.end());
        // if(!point2.empty()) sort(point2.begin(), point2.end());
        if (point1.empty())
        {
            i = -1;
        }
        else
        {
            i = point1.size() - 1;
            sort(point1.begin(), point1.end());
        }
        if (point2.empty())
        {
            j = -1;
        }
        else
        {
            j = point2.size() - 1;
            sort(point2.begin(), point2.end());
        }
        int sum = 0, requiredPoint = 0;
        while (i >= 0 || j >= 0)
        {
            if (sum >= m)
            {
                break;
            }
            if (i >= 0 && j >= 0)
            {
                if (sum + point1[i] >= m)
                {
                    sum += point1[i];
                    i--;
                    requiredPoint++;
                }
                else
                {
                    if (i >= 1)
                    {
                        if (point1[i] + point1[i - 1] >= point2[j])
                        {
                            sum += point1[i] + point1[i - 1];
                            i -= 2;
                            requiredPoint += 2;
                        }
                        else
                        {
                            sum += point2[j];
                            j--;
                            requiredPoint += 2;
                        }
                    }
                    else
                    {
                        sum += point2[j];
                        j--;
                        requiredPoint += 2;
                    }
                }
            }
            else if (j < 0)
            {
                sum += point1[i];
                i--;
                requiredPoint++;
            }
            else
            {
                sum += point2[j];
                j--;
                requiredPoint += 2;
            }
        }
        if (sum < m)
        {
            cout << "-1\n";
        }
        else
        {
            cout << requiredPoint << "\n";
        }
    }
    return 0;
}