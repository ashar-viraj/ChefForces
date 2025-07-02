// 4 6 4 10 2 9 3 7 9 1
#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(i = a; i < b; i++)
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, temp, a, b, c, d;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int sum = 0, oc = 0;
        rep(i, 0, n)
        {
            cin >> temp;
            if(temp % 2)
            {
                oc++;
            }
            sum += temp;
        }
        if(oc % 2)
        {
            cout << "2\n";
        }
        else
        {
            cout << "1\n";
        }
    }
    return 0;
}