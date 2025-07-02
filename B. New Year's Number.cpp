#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, temp, d;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a = 0, b, r;
        bool valid = false;
        while(a*2020 <= n)
        {
            r = n-(a*2020);
            if(r%2021==0)
            {
                valid = true;
                cout << "YES\n";
                break;
            }
            a++;
        }
        if(!valid)
        {
            cout << "NO\n";
        }

    }
    return 0;
}