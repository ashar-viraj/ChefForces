// Codeforces Round #693
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, w, h;
    cin >> t;
    while (t--)
    {
        int wc = 0, hc = 0;
        cin >> w >> h >> n;
        while (w % 2 == 0)
        {
            wc++;
            w /= 2;
        }
        while (h % 2 == 0)
        {
            hc++;
            h /= 2;
        }
        // cout << "wc = " << wc << ", hc = " << hc << "\n";
        if (n <= (pow(2, wc) * pow(2, hc)))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}