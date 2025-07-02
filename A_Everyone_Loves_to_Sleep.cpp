#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int s;
        cin >> s;

        if (s == 0)
        {
            cout << 0 << endl;
            continue;
        }

        string sol = "";
        int k = 9;
        while (s)
        {
            if (s > k)
            {
                sol = to_string(k) + sol;
                s -= k;
                k--;
            }
            else
            {
                sol = to_string(s) + sol;
                s = 0;
            }
        }
        cout << sol << endl;
    }
}
