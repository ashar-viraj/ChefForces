#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v, ans, maxElements;
        map<int, int> idx;
        bool picked[n + 1];
        rep(i, 0, n)
        {
            cin >> itemp;
            v.push_back(itemp);
            idx[v[i]] = i;
            picked[v[i]] = false;
        }
        int max = n;
        for (i = n - 1; i >= 0; i--)
        {
            if (v[i] == max)
            {
                maxElements.push_back(max);
                picked[v[i]] = true;
                while(picked[max])
                {
                    max--;
                }
            }
            picked[v[i]] = true;
        }
        i = 0;
        while (!v.empty())
        {
            copy(v.begin() + idx[maxElements[i]], v.end(), back_inserter(ans));
            v.erase(v.begin() + idx[maxElements[i]], v.end());
            i++;
        }
        for (auto e : ans)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}