#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        string s;
        cin >> n;
        int inp[n], sorted[n], firstN = 0, lastN = n - 1, firstS = 0, lastS = n - 1;
        rep(i, 0, n)
        {
            cin >> inp[i];
            sorted[i] = inp[i];
        }
        cin >> s;

        while (firstN < n && s[firstN] != 'N')
            firstN++;
        while (firstS < n && s[firstS] != 'S')
            firstS++;
        while (lastN >= 0 && s[lastN] != 'N')
            lastN--;
        while (lastS >= 0 && s[lastS] != 'S')
            lastS--;
        sort(sorted, sorted + n);
        int firstDiff = 0, lastDiff = n - 1;
        while (firstDiff < n && inp[firstDiff] == sorted[firstDiff])
            firstDiff++;
        while (lastDiff >= 0 && inp[lastDiff] == sorted[lastDiff])
        {
            lastDiff--;
        }
        if (firstDiff == n)
        {
            cout << "0\n";
        }
        else if (firstDiff == lastDiff || s[firstDiff] != s[lastDiff])
        {
            cout << "1\n";
        }
        else
        {
            bool isThereN = false, isThereS = false;
            for (auto e : s)
                if (e == 'N')
                {
                    isThereN = true;
                    break;
                }
            for (auto e : s)
                if (e == 'S')
                {
                    isThereS = true;
                    break;
                }
            if (!isThereN || !isThereS)
            {
                cout << "-1\n";
            }
            else
            {
                cout << "2\n";
            }
        }
    }
    return 0;
}