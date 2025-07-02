#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define endl '\n' 
#define mp make_pair


bool prime[100001];

void SieveOfEratosthenes(int n = 100000)
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

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
        rep(i, 0 ,n)
            cin >> a[i];
        if(a[0] == n && a[n-1] == 1)
            cout << 3 << endl;
        else if(a[0] != 1 && a[n-1] != n)
            cout << 2 << endl;
        else if(a[0] == 1 && a[n-1] != n || a[n-1] == n && a[0] != 1)
            cout << 1 << endl;
        else
        {
            bool asc = true;
            rep(i, 1, n)
            {
                if(a[i] < a[i-1])
                {
                    asc = false;
                    break;
                }
            }
            if(!asc)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }        
    }
    return 0;
}