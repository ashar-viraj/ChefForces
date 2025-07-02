#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, n, temp, d;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> v;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        if (n <= 2)
        {
            cout << 0 << "\n";
            continue;
        }
        ll s = 0, diff = abs(v[0] - v[1]), mx, a, b, c, d, e, f;
        s = 1;
        mx = abs(v[0] - v[2]) > abs(v[1] - v[2]) ? abs(v[0] - v[2]) : abs(v[1] - v[2]);

        for (i = 2; i < n; i++)
        {
            if (abs(v[i] - v[i - 1]) > diff)
            {
                s = i;
                diff = abs(v[i] - v[i - 1]);
                // if (abs(v[i] - v[i - 2]) < abs(v[i - 1] - v[i - 2]))
                // {
                //     s = i - 1;
                // }
                // else
                // {
                //     s = i;
                // }
            }
            else if (abs(v[i] - v[i - 1]) == diff)
            {
                cout << "s = " << s << '\n';
                if (s == 1)
                {
                    a = abs(v[s] - v[s + 1]);
                    b = abs(v[s - 1] - v[s + 1]);
                    a = a > b ? a : b;
                }
                else
                {
                    a = abs(v[s] - v[s - 2]);
                    b = abs(v[s + 1] - v[s]);
                    a = a > b ? a : b;
                    b = abs(v[s - 1] - v[s - 2]);
                    c = abs(v[s + 1] - v[s - 1]);
                    b = b > c ? b : c;
                    a = a > b ? a : b;
                }
                if (i == n - 1)
                {
                    b = abs(v[i] - v[i - 2]);
                    c = abs(v[i - 1] - v[i - 2]);
                    b = b < c ? b : c;
                }
                else
                {
                    b = abs(v[i] - v[i - 2]);
                    c = abs(v[i + 1] - v[i - 1]);
                    b = b > c ? b : c;
                    c = abs(v[i - 1] - v[i - 2]);
                    d = abs(v[i - 1] - v[i + 1]);
                    c = c > d ? c : d;
                    b = b > c ? b : c;
                }
                cout << "in for loop i =  " << i << ", b = " << b << ", a = " << a << "\n";
                if (b < a)
                {
                    s = i;
                }
            }
        }
        cout << "s = " << s << "\n";
        if (s == 1)
        {
            a = abs(v[s] - v[s + 1]);
            b = abs(v[s - 1] - v[s + 1]);
            if (a > b)
            {
                v[s] = v[s - 1];
            }
            else
            {
                v[s - 1] = v[s];
            }
        }
        else if (s == n - 1)
        {
            a = abs(v[s - 1] - v[s - 2]);
            b = abs(v[s] - v[s - 2]);
            if (a > b)
            {
                v[s - 1] = v[s];
            }
            else
            {
                v[s] = v[s - 1];
            }
        }
        else
        {
            a = abs(v[s] - v[s - 2]);
            b = abs(v[s + 1] - v[s]);
            a = a > b ? a : b;
            b = abs(v[s - 1] - v[s - 2]);
            c = abs(v[s + 1] - v[s - 1]);
            b = b > c ? b : c;
            if (a > b)
            {
                v[s - 1] = v[s];
            }
            else
            {
                v[s] = v[s - 1];
            }
        }
        for (i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        ll operation = 0;
        for (i = 1; i < n; i++)
        {
            operation += abs(v[i] - v[i - 1]);
        }
        cout << operation << "\n";
    }
    return 0;
}