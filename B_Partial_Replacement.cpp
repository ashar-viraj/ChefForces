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

    int t, i, j, n, itemp, k;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        vector<int> pos;
        rep(i, 0, s.size())
        {
            if(s[i] =='*')
            {
                pos.push_back(i);
            }
        }
        if(pos.size() <= 2)
        {
            cout << pos.size() << endl;
            continue;
        }
        int idx = pos[0], count = 2;
        rep(i, 1, pos.size()-1)
        {
            if(pos[i] - idx == k)
            {
                idx = pos[i];
                count ++;
            }
            else if(pos[i] - idx > k)
            {
                idx = pos[i-1];
                i--;
                count++;
            }
        }
        if(pos[pos.size()-1] - idx > k)
            count++;
        cout << count << endl;
    }
    return 0;
}