#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
#define f first
#define s second
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    int n;
    cin >> n;
    int total = (n * (n + 1)) / 2;
    if (total % 2)
    {
        cout << "NO";
        return 0;
    }

    int req = total / 2;
    vector<int> a, b;
    int curr = n;
    while (req >= curr)
    {
        a.push_back(curr);
        req -= curr;
        curr--;
    }
    if (req > 0)
        a.push_back(req);

    int taken = req;
    while (curr > 0)
    {
        if (curr != taken)
            b.push_back(curr);
        curr--;
    }

    cout << "YES\n"
         << a.size() << endl;
    for (auto e : a)
        cout << e << ' ';
    cout << endl << b.size() << endl;
    for (auto e : b)
        cout << e << ' ';
    return 0;
}