// Codeforces Round #688 (Div. 2)
#include <bits/stdc++.h>
using namespace std;

int cancelTheTrains(vector<int> v1, vector<int> v2, int a, int b)
{
    int count = 0, i = 0, j = 0;
    while (i < a && j < b)
    {
        if (v1[i] == v2[j])
        {
            count++;
            i++;
            j++;
        }
        else if (v1[i] > v2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return count;
}

int main()
{
    int T, i, a, b, temp;
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        vector<int> v1, v2;
        for (i = 0; i < a; i++)
        {
            cin >> temp;
            v1.push_back(temp);
        }
        for (i = 0; i < b; i++)
        {
            cin >> temp;
            v2.push_back(temp);
        }
        cout << cancelTheTrains(v1, v2, a, b) << endl;
    }
    return 0;
}