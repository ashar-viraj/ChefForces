#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> a(n), c(n);
        stack<int> b1, b2;
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        if (n <= 2)
        {
            cout << "YES\n";
            continue;
        }
        b1.push(a[n - 1]);
        bool valid = true;
        for (int i = n - 2; i >= 0; i--)
        {
            if ((b1.size() + b2.size()) % 2 != 0)
            {
                if (b1.size() > b2.size())
                {
                    int temp = b1.top();
                    b1.pop();
                    b1.push(min(temp, a[i]));
                    b2.push(max(temp, a[i]));
                }
                else
                {
                    int temp = b2.top();
                    b2.pop();
                    b1.push(min(temp, a[i]));
                    b2.push(max(temp, a[i]));
                }
            }
            else
            {
                b1.push(a[i]);
            }
        }
        int k = 0, i = b1.size() - 1, j = 0;
        while (k < n)
        {
            if ((b1.size() + b2.size()) % 2 != 0)
            {
                if (b1.size() > b2.size())
                {
                    c[k] = b1.top();
                    b1.pop();
                }
                else
                {
                    c[k] = b2.top();
                    b2.pop();
                }
                k++;
            }
            else if (b1.size() && b2.size())
            {
                if (b1.top() < b2.top())
                {
                    c[k] = b1.top();
                    b1.pop();
                }
                else
                {
                    c[k] = b2.top();
                    b2.pop();
                }
                k++;
            }
            else if (b1.size())
            {
                c[k] = b1.top();
                k++;
                b1.pop();
            }
            else
            {
                c[k] = b2.top();
                k++;
                b2.pop();
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (c[i] < c[i - 1])
            {
                valid = false;
                break;
            }
        }
        out(valid);
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> a(n), b1, b2, c(n);
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        if (n <= 2)
        {
            cout << "YES\n";
            continue;
        }
        b1.push_back(a[n - 1]);
        b2.push_back(a[n - 2]);
        bool valid = true;
        for (int i = n - 3; i >= 0; i--)
        {
            if ((b1.size() + b2.size()) % 2 != 0)
            {
                if (b1.size() > b2.size())
                {
                    int temp = b1.back();
                    b1.pop_back();
                    b1.push_back(min(temp, a[i]));
                    b2.insert(b2.begin(), max(temp, a[i]));
                }
                else
                {
                    int temp = b2[0];
                    b2.pop_back();
                    b1.push_back(min(temp, a[i]));
                    b2.insert(b2.begin(), max(temp, a[i]));
                }
            }
            else
            {
                b1.push_back(a[i]);
            }
        }
        int k = 0, i = b1.size() - 1, j = 0;
        while (k < n)
        {
            if (i >= 0 && j < b2.size() && ((i + 1) + (b2.size() - j)) % 2 != 0)
            {
                if ((i + 1) > (b2.size() - j))
                {
                    c[k] = b1[i];
                    i--;
                }
                else
                {
                    c[k] = b2[j];
                    j++;
                }
                k++;
            }
            else if (i >= 0 && j < b2.size())
            {
                if (b1[i] < b2[j])
                {
                    c[k] = b1[i];
                    i--;
                }
                else
                {
                    c[k] = b2[j];
                    j++;
                }
                k++;
            }
            else if (i >= 0)
            {
                c[k] = b1[i];
                k++;
                i--;
            }
            else
            {
                c[k] = b2[j];
                k++;
                j++;
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (c[i] < c[i - 1])
            {
                valid = false;
                break;
            }
        }
        out(valid);
    }
    return 0;
}
*/