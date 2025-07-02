#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define endl '\n' 
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        rep(i, 0, n)
            cin >> a[i];
        int c, m;
        int min, max;
        if(a[1] > a[0])
            c = a[1] - a[0];
        else
        {
            c = a[2]-a[1];
        }
        bool found = false, same = true;
        rep(i, 1, n)
        {
            if(a[i] != a[i-1])
            {
                same = false;
            }
            if(a[i] < a[i-1])
            {
                found = true;
                min = a[i];
                max = a[i-1];
                m = max + (c-min);
                break;
            }
        }
        if(same)
        {
            cout << "0\n";
            continue;
        }
        rep(i, 0, n)
        {
            if(a[i] >= m)
            {
                found = false;
                break;
            }
        }
        if(!found)
        {
            cout << "-1\n";
            continue;
        }
        rep(i, 1, n)
        {
            if(a[i-1] == a[i])
            {
                found = false;
                break;
            }
            if((a[i-1] + c) % m != a[i])
            {
                found = false;
                break;
            }
        }
        if(found)
            cout << m << " " << c << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}