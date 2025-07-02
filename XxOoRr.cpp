#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define endl '\n' 
#define mp make_pair


bool prime[10000001];
vector<int> primes;
//50001

void SieveOfEratosthenes()
{
    int n = 10000000;
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
    rep(i, 2, 50001)
    {
        if (prime[i])
            primes.push_back(i);
    }
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int countnoofprimes(int n)
{
    int count = 0, temp = n, i = 0;

    for (auto e : primes)
    {
        while (temp % e == 0)
        {
            temp /= e;
            count++;
        }
        if(temp == 1)
        {
            break;
        }
    }
    if (temp > 1)
        count++;
    return count;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int a[n], pow2[30], count[30], ans = 0;
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        rep(i, 0, 30)
        {
            pow2[i] = pow(2,i);
            count[i] = 0;
        }
        rep(i, 0, n)
        {
            rep(j, 0, 30)
            {
                if(pow2[j] > a[i])
                {
                    break;
                }
                if(a[i] & pow2[j])
                    count[j]++;
            }
        }
        rep(i, 0, 30)
        {
            ans += ceil((float)count[i]/(float)k);
        }
        cout << ans << endl;
    }
    return 0;
}