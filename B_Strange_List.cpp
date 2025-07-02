// Codeforces Round #694 (Div. 2)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t, i, n, k;
    cin >> t;
    while (t--)
    {
        long long int itemp, sum = 0;
        cin >> n >> k;
        vector<tuple<long long int, long long int, long long int>> v;
        for (i = 0; i < n; i++)
        {
            cin >> itemp;
            sum += itemp;
            v.push_back(make_tuple(itemp, k, 1));
        }
        bool stop = false;
        sum = 0;
        for (i = 0; i < v.size(); i++)
        {
            if (get<0>(v[i]) % k == 0 && !stop)
            {
                v.push_back(make_tuple(get<0>(v[i]) / k, k, get<2>(v[i]) * k));
            }
            else
            {
                stop = true;
            }
            sum += get<0>(v[i]) * get<2>(v[i]);
        }
        cout << sum << "\n";
    }
    return 0;
}