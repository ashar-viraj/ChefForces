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

    int t, i, j, n, itemp, q, query;
    vector<int> Deck;
    bool Occurred[51];
    int FirstOccurrence[51];

    memset(Occurred, false, sizeof(Occurred));
    memset(FirstOccurrence, -1, sizeof(FirstOccurrence));

    cin >> n >> q;

    rep(i, 0, n)
    {
        cin >> itemp;
        if (!Occurred[itemp])
        {
            Occurred[itemp] = true;
            FirstOccurrence[itemp] = i;
        }
        Deck.push_back(itemp);
    }

    int pos;
    rep(i, 0, q)
    {
        cin >> query;
        pos = find(Deck.begin(), Deck.end(), query) - Deck.begin();
        cout << pos + 1 << " ";
        rotate(Deck.begin(), Deck.begin() + pos, Deck.begin() + pos + 1);
    }
    return 0;
}