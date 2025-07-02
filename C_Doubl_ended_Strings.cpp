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
    string s1, s2;
    cin >> t;
    while (t--)
    {
        cin >> s1 >> s2;
        vector<string> vs1, vs2;
        rep(i, 0, s1.size())
        {
            rep(j, 1, s1.size()-i+1)
            {
                vs1.push_back(s1.substr(i, j));
            }
        }
        rep(i, 0, s2.size())
        {
            rep(j, 1, s2.size()-i+1)
            {
                vs2.push_back(s2.substr(i, j));
            }
        }
        int maxLength = 0;
        rep(i, 0, vs1.size())
        {
            rep(j, 0, vs2.size())
            {
                if(vs1[i] == vs2[j] && vs1[i].length() > maxLength)
                    maxLength = vs1[i].length();
            }
        }
        cout << s1.length() + s2.length() - 2 * maxLength << endl;
    }
    return 0;
}