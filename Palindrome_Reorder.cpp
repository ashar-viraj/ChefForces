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
    string s;
    cin >> s;
    map<char, int> freq;
    int one = 0;
    for (auto e : s)
        freq[e]++;
    for (auto e : freq)
        one += ((e.second % 2) == 1);

    if (one > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    string pref = "", mid = "", suff = "";
    for (auto e : freq)
    {
        int rem = e.second;
        while (rem > 1)
        {
            pref += e.first;
            suff += e.first;
            rem -= 2;
        }
        if (rem > 0)
            mid += e.first;
    }

    reverse(suff.begin(), suff.end());
    cout << pref << mid << suff;

    return 0;
}