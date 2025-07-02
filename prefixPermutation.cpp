#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define endl '\n' 
#define mp make_pair
#define MOD 1000000007


int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        int k;
        cin >> n >> k;
        int a[k];
        for(int i = 0; i < k; i++)
            cin >> a[i];
        sort(a, a+k);
        int i = 0, j = a[0], lastAdded = 0;
        while(i != k)
        {
            j = a[i];
            while(j > lastAdded)
            {
                cout << j << ' ';
                j--;
            }
            lastAdded = a[i];
            i++;
        }
        cout << endl;
    }
    return 0;
}