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

    int t, i, n, temp, a, b, c, d, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if(n%k == 0)
        {
            cout  << "1\n";
        }
        else if(n > k)
        {
            cout << "2\n";
        }
        else
        {
            if(k%n == 0)
            {
                cout << k/n << "\n";
            }
            else
            {
                cout  << (k/n)+1 << "\n";
            }
        }
    }
    return 0;
}