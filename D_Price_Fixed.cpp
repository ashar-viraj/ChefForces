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

bool compare(const pair<int, int> a, const pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    if (a.second > b.second)
        return false;
    return a.first < b.first;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp, itemp1, itemp2, BuyedProducts = 0, cost = 0;
    cin >> n;
    vector<pair<int, int>> RequiredProducts;
    rep(i, 0, n)
    {
        cin >> itemp1 >> itemp2;
        RequiredProducts.push_back(make_pair(itemp1, itemp2));
    }
    sort(RequiredProducts.begin(), RequiredProducts.end(), compare);
    i = 0, j = RequiredProducts.size() - 1;
    while (i < j)
    {
        if (RequiredProducts[i].second <= BuyedProducts)
        {
            BuyedProducts += RequiredProducts[i].first;
            cost += RequiredProducts[i].first;
            i++;
            continue;
        }
        else
        {
            if (RequiredProducts[j].first + BuyedProducts <= RequiredProducts[i].second)
            {
                BuyedProducts += RequiredProducts[j].first;
                cost += RequiredProducts[j].first * 2;
                j--;
            }
            else
            {
                itemp = RequiredProducts[i].second - BuyedProducts;
                BuyedProducts += itemp;
                cost += itemp * 2;
                RequiredProducts[j].first -= itemp;
            }
        }
    }
    if (i == j)
    {
        if (BuyedProducts >= RequiredProducts[i].second)
        {
            cost += RequiredProducts[i].first;
            BuyedProducts += RequiredProducts[i].first;
        }
        else
        {
            cost += min(RequiredProducts[i].first + RequiredProducts[i].second - BuyedProducts, RequiredProducts[i].first * 2);
            BuyedProducts += RequiredProducts[i].first;
        }
    }
    cout << cost;
    return 0;
}