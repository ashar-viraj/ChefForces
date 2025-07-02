#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define f first
// #define s second
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

string toBinary(int i)
{
    string s = "";
    while (i)
    {
        char c = '0' + (i % 2);
        s = c + s;
        i /= 2;
    }
    return s;
}

string complement(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            s[i] = '1';
        else
            s[i] = '0';
    }
    string comp;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
            return s.substr(i);
}

int toDecimal(string s)
{
    reverse(s.begin(), s.end());
    int num = 0, pow = 1;
    for (int i = 0; i < s.size(); i++)
    {
        num += (s[i] - '0') * pow;
        pow *= 2;
    }
    return num;
}

int32_t main()
{

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        if (n == 1)
        {
            cout << "1\n1\n";
            continue;
        }
        if (((n + 1) & n) == 0)
        {
            cout << "-1\n";
            continue;
        }
        vector<string> v(n);
        unordered_map<string, bool> visited;
        unordered_map<string, string> pairwith;
        for (int i = 1; i <= n; i++)
            v[i - 1] = toBinary(i);
        bool pos = true;
        for (int i = n - 1; i >= 0; i--)
        {
            if (!visited[v[i]])
            {
                string comp = complement(v[i]);
                if (visited[comp])
                    pos = false;
                visited[v[i]] = true;
                visited[comp] = true;
                pairwith[v[i]] = comp;
                pairwith[comp] = v[i];
            }
        }
        if (!pos)
        {
            cout << "-1\n";
            continue;
        }
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            int n1, n2;
            n1 = toDecimal(v[i]);
            n2 = toDecimal(pairwith[v[i]]);
            a[i] = n1;
            b[i] = n2;
        }
        for(auto e : a) cout << e << ' ';
        cout << endl;
        for(auto e : b) cout << e << ' ';
        cout << endl;
    }
    return 0;
}