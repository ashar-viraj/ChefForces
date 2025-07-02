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

    int t, i, j, n, itemp, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> h(n + 1);
        bool possible = true;
        h[n] = INT_MIN;
        cin >> h[0];
        int min = 0, max = 0;
        rep(i, 1, n)
        {
            cin >> h[i];
            if (h[i] < h[min])
            {
                min = i;
            }
            if (h[i] > h[max])
            {
                max = i;
            }
        }
        int a = h[min];
        rep(i, 0, n + 1)
            h[i] -= a;
        int times = 0, l = 0, temp = 0;
        while (k)
        {
            if (l == n)
            {
                possible = false;
                break;
            }
            if (l == 0)
            {
                l = temp;
            }
            if (h[l] > h[l + 1])
            {
                l++;
            }
            else if (h[l] == h[l + 1])
            {
                if (l > 0 & h[l - 1] < h[l])
                    l--;
                else
                    l++;
                temp = l;
            }
            else
            {
                if(l > 0 & h[l-1] < h[l])
                {
                    l--;
                }
                h[l]++;
                k--;
            }
        }
        if (possible)
        {
            cout << l + 1 << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}
/*
14
8 1
8 7 6 4 5 7 5 8
8 2
8 7 6 4 5 7 5 8
8 3
8 7 6 4 5 7 5 8
8 4
8 7 6 4 5 7 5 8
8 5
8 7 6 4 5 7 5 8
8 6
8 7 6 4 5 7 5 8
8 7
8 7 6 4 5 7 5 8
8 8
8 7 6 4 5 7 5 8
8 9
8 7 6 4 5 7 5 8
8 10
8 7 6 4 5 7 5 8
8 11
8 7 6 4 5 7 5 8
8 12
8 7 6 4 5 7 5 8
8 13
8 7 6 4 5 7 5 8
8 14
8 7 6 4 5 7 5 8
*/