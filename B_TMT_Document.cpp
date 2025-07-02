#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
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
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        int countt = 0, countm = 0, countt2 = 0;
        vector<int> TBeforeM, TAfterM;
        rep(i, 0, s.size())
        {
            if (s[i] == 'T')
                countt++;
            else
            {
                TBeforeM.push_back(countt);
                countm++;
            }
        }
        for(i = s.size() -1; i >= 0; i--)
        {
            if(s[i] == 'T')
                countt2++;
            else
                TAfterM.push_back(countt2);
        }
        if (countm * 2 != countt || s[0] == 'M' || s[n-1] == 'M')
        {
            cout << "NO\n";
            continue;
        }
        bool possible = true;
        rep(i, 0, TBeforeM.size())
        {
            if(TBeforeM[i] < (i+1) || TAfterM[i] < i+1)
            {
                possible = false;
                break;
            }
        }
        if(possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}