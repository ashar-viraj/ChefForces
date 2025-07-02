#include <bits/stdc++.h>
using namespace std;

int sequenceAndSwaps(vector<int> v, int n, int x)
{
    int count = 0, i;
    if (n == 1)
    {
        return 0;
    }
    bool not_sorted = true;
    i = 0;
    while (not_sorted)
    {
        not_sorted = false;
        for (i = 1; i < n; i++)
        {
            if (v[i] < v[i - 1])
            {
                not_sorted = true;
                break;
            }
        }
        if (!not_sorted)
        {
            break;
        }
        count++;
        i = 0;
        while (i < n && v[i] <= x)
        {
            i++;
        }
        if (i == n)
        {
            return -1;
        }
        swap(v[i], x);
    }
    // if (count == n)
    //     return -1;
    return count;
}

int main()
{
    int T, i, N, X, temp;
    cin >> T;
    while (T--)
    {
        cin >> N >> X;
        vector<int> v;
        for (i = 0; i < N; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        cout << sequenceAndSwaps(v, N, X) << endl;
    }
    return 0;
}