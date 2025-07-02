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
    cin >> n;
    int a[n];
    map<int, int> m;
    rep(i, 0, n)
    {
        cin >> a[i];
        m[a[i]] = 0;
    }
    vector<int> v;
    for(i = n-1; i>= 0; i--)
    {
        if(m[a[i]] == 0)
        {
            v.insert(v.begin(), a[i]);
            m[a[i]] = 1;
        }
    }
    cout << v.size() << endl;
    rep(i, 0, v.size())
    {
        cout << v[i] << " ";
    }
    return 0;
}