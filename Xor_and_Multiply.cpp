#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<int> primeFactors(int n)
{
    vector<int> factors;
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            factors.push_back(i);
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        factors.push_back(n);

    return factors;
}

int cost(int sou, int des)
{
    vector<int> factorssou = primeFactors(sou), factorsdes = primeFactors(des);
    int total = 0;
    for (auto e : factorsdes)
        total += e;
    for (auto e : factorssou)
        total -= e;

    return total;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int q;
        cin >> n >> q;
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            int gcd = __gcd(a, b);
            int costa = cost(gcd, a), costb = cost(gcd, b);
            cout << costa + costb << endl;
        }
    }
    return 0;
}