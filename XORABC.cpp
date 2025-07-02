#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

string convertToBinary(int n)
{
    string bin = "";
    while (n)
    {
        if (n % 2)
            bin += '1';
        else
            bin += '0';
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

void binToDeci(string s)
{
    reverse(s.begin(), s.end());
    int ans = 0, i = 1;
    for (auto e : s)
    {
        if (e == '1')
            ans += i;
        i *= 2;
    }
    cout << ans << ' ';
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        string bin = convertToBinary(n);
        int freq = 0;
        for (int i = 0; i < bin.size() - 1; i++)
            if (bin[i] == '1')
                freq++;
        if (bin[bin.size() - 1] == '1' || freq == 1)
        {
            cout << "-1\n";
            continue;
        }

        string a = "", b = "", c = "";
        char appa = '0', appb = '1', appc = '1', temp;
        for (int i = bin.size() - 1; i > 0; i--)
        {
            if (bin[i - 1] == '0')
            {
                a = '0' + a, b = '0' + b, c = '0' + c;
            }
            else if (bin[i - 1] == '1')
            {
                a = appb + a;
                b = appa + b;
                c = '1' + c;
                temp = appa, appa = appb, appb = temp;
            }
        }
        binToDeci(a);
        binToDeci(b);
        binToDeci(c);
        cout << endl;
    }
    return 0;
}