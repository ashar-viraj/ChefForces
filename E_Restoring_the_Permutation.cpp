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
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n], deletedNumbers = 0, minimal[n], maximal[n];
        vector<int> notInArray, notInArray2;
        rep(i, 1, n + 1)
        {
            notInArray.push_back(i);
        }
        rep(i, 0, n)
        {
            cin >> a[i];

            if(i == 0)
            {
                notInArray.erase(notInArray.begin() + a[0] - 1);
                deletedNumbers++;
            }
            else if(a[i] != a[i-1])
            {
                notInArray.erase(notInArray.begin() + a[i] - 1 - deletedNumbers);
                deletedNumbers++;
            }
        }
        deletedNumbers--;
        cout << deletedNumbers << ": deleted numbers\n";
        copy(notInArray.begin(), notInArray.end(), notInArray2.begin());
        minimal[0] = a[0];
        j = 0;
        maximal[0] = a[0];
        rep(i, 1, n)
        {
            if(a[i] == a[i-1])
            {
                minimal[i] = notInArray[j++];
            }
            else
            {
                minimal[i] = a[i];
            }
        }


        // rep(i, 0, n)
        // {
        //     cout << minimal[i] << " ";
        // }
        // cout << endl;
    }
    return 0;
}