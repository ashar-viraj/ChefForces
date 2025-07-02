#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define um unordered_map
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool compare(int a, int b)
{
    if (a % 3 == 0 && b % 3 == 0)
        return a < b;
    if (a % 3 == 0)
        return true;
    if (b % 3 == 0)
        return false;
    return a < b;
}

int32_t main()
{
    vector<int> v = {1, 9, 6, 4, 15, 47, 54, 51, 2, 3, 6, 4, 5, 8, 9, 93};
    sort(v.begin(), v.end(), compare);
    for (auto e : v)
        cout << e << ' ';
    return 0;
}