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
        int oc = 0, ec = 0;
        rep(i, 0, n)
        {
            cin >> temp;
            if(temp%2)
            {
                oc++;
            }
            else
            {
                ec++;
            }
        }
        cout << ((oc < ec)? oc : ec) << "\n";
    }
    return 0;
}