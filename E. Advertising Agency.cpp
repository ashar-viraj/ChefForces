#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (i = a; i < b; i++)
#define mp make_pair

int fact[100001], MOD=1000000007;

int fast_pow(int base, int n, int M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    int halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
int findMMI_fermat(int n,int M)
{
    return fast_pow(n,M-2,M);
}

int32_t main()
{
    fact[0]=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, temp, a, b, c, d, k;
    i = 1;
    while(i<=100000)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        i++;
    }
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        map<int, int> m;
        set<int> s;
        rep(i, 0, n)
        {
            cin >> temp;
            m[temp]++;
        }
        for (auto itr : m)
        {
            s.insert(itr.first);
        }
        // nCr = bCa

        for (auto itr = s.rbegin(); itr != s.rend(); itr++)
        {
            // cout << *itr << " " << m[*itr] << " " << k << "\n";
            if(k-m[*itr] <= 0)
            {
                b = m[*itr];
                a = k;
                break;
            }
            k-=m[*itr];
        }
        // cout << "b = " << b << ", a = " << a << "\n";
        int numerator = fact[b];
        int denominator = (fact[a]*fact[b-a])%MOD;
        int mmi_denominator=findMMI_fermat(denominator,MOD);
        cout << (numerator*mmi_denominator)%MOD << "\n";
    }
    return 0;
}