#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp, a, b;
    cin >> t;
    while (t--)
    {
        string s1, s2, s;
        int c0 = 0, c1 = 0, r0, r1, extra = 0;
        cin >> a >> b;
        cin >> s;
        if ((a % 2 && b % 2) || (a + b) != s.size())
        {
            cout << "-1\n";
            continue;
        }
        n = s.size();
        bool found = true;
        rep(i, 0, n)
        {
            if (s[i] == '0')
            {
                if (s[n - (i + 1)] == '?')
                    s[n - (i + 1)] = '0';
                else if (s[n - (i + 1)] == '1')
                {
                    found = false;
                    break;
                }
            }
            else if (s[i] == '1')
            {
                if (s[n - (i + 1)] == '?')
                    s[n - (i + 1)] = '1';
                else if (s[n - (i + 1)] == '0')
                {
                    found = false;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "-1\n";
            continue;
        }
        rep(i, 0, n)
        {
            if (s[i] == '0')
                c0++;
            else if (s[i] == '1')
                c1++;
        }
        if (c0 <= a && c1 <= b)
        {
            rep(i, 0, n)
            {
                if (i == (n + 1) / 2 - 1 && n % 2)
                {
                    if ((a-c0) % 2)
                    {
                        s[i] = '0';
                        c0++;
                    }
                    else if ((b-c1)%2)
                    {
                        s[i] = '1';
                        c1++;
                    }
                }
                if (s[i] == '?')
                {
                    if (c0 != a && c0 != a - 1)
                    {
                        s[i] = '0';
                        s[n - (i + 1)] = '0';
                        c0 += 2;
                    }
                    else if (c1 != b && c1 != b - 1)
                    {
                        s[i] = '1';
                        s[n - (i + 1)] = '1';
                        c1 += 2;
                    }
                }
            }
            if (c0 == a && c1 == b)
                cout << s << endl;
            else
                cout << "-1\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}