#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i != b; i++)
#define endl '\n'
#define mp make_pair

int32_t main()
{
    map<int, int> m;
    int n, y;
    cin >> n >> y;

    int factorCount[n + 1];
    bool prime[n + 1];
    rep(i, 0, n + 1)
    {
        factorCount[i] = 0;
        prime[i] = true;
    }
    rep(i, 2, n + 1)
    {
        if (prime[i])
        {
            factorCount[i] = 1;
            for (int j = i * 2; j <= n; j += i)
            {
                factorCount[j]++;
                prime[j] = false;
            }
        }
    }
    cout << "Prime Numbers:\n";
    rep(i, 1, n + 1)
    {
        if(factorCount[i] > y)
            cout << i << ":-" << factorCount[i] << "\n";
    }
    // cout << "\nNot Prime Numbers:\n";
    // rep(i, 1, n + 1)
    // {
    //     if (!prime[i])
    //     {
    //         cout << i << ":-" << factorCount[i] << "\n";
    //     }
    // }
    return 0;
}