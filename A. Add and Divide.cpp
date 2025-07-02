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

    int t, i, j, itemp, atemp, btemp;
    float a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        int ai = a, bi = b;
        int count = INT_MAX, countTemp;
        bool increaseByOnea = false, increaseByOneb = false;
        if (a == b)
        {
            cout << "2\n";
            continue;
        }
        if (floor(a / b) == 0)
        {
            cout << "1\n";
            continue;
        }
        if (b == 1)
        {
            b++;
            bi = b;
            increaseByOnea = true;
        }
        for (i = bi; i <= (int)(sqrt(ai)) + 1; i++)
        {
            countTemp = (i - bi) + ceil(log2(a) / log2(i));
            if (countTemp < count)
                count = countTemp;
        }
        if (increaseByOnea)
        {
            count++;
        }
        cout << count << endl;
    }
    return 0;
}