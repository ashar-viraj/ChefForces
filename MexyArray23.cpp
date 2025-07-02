#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        int b[n], ma = -1;
        rep(i, 0, n)
        {
            cin >> b[i];
            if (b[i] > ma)
                ma = b[i];
        }
        int a[n];
        bool valid = true;
        unordered_map<int, int> freq;
        int rep = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] > i + 1 || )
            {
                valid = false;
            }
            if (b[i] != -1)
            {
                freq[b[i]]++;
                if(freq[b[i]] > 1)
                    rep++;
            }
        }

        if (!valid)
        {
            cout << "-1\n";
            continue;
        }

        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++)
        {
            a[i] = i;
            idx[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            if (b[i] != -1)
            {
                if (idx[b[i]] <= i)
                {
                    if (i == n - 1)
                    {
                        continue;
                    }
                    else
                    {
                        int val1 = b[i], val2 = a[i + 1];
                        int idx1 = idx[val1], idx2 = idx[val2];
                        idx[val2] = idx1, idx[val1] = idx2;
                        a[idx1] = val2, a[idx2] = val1;
                    }
                }
            }
        }
        rep(i, 0, n)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}