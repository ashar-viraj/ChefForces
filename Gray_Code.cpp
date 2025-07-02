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

void solve(int curr, bool visited[], int n, vector<int> &v)
{
    visited[curr] = true;
    v.push_back(curr);

    for (int i = 0; i < n; i++)
    {
        if (!visited[(curr ^ (1 << i))])
            solve((curr ^ (1 << i)), visited, n, v);
    }
}

void binary(int n, int len)
{
    string s = "";
    while (n)
    {
        if (n & 1)
            s += "1";
        else
            s += "0";
        n /= 2;
    }
    while ((int)s.size() != len)
        s += "0";
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int32_t main()
{
    int n;
    cin >> n;
    bool visited[1 << n] = {false};
    vector<int> v;
    solve(0, visited, n, v);

    for (auto &e : v)
        binary(e, n);

    return 0;
}