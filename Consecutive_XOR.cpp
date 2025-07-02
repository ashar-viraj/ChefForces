
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define f first
#define s second
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
        string a, b;
        cin >> a >> b;

        // if (n == 2)
        // {
        //     if (a == b || b == "00")
        //         out(true);
        //     else
        //         out(false);
        //     continue;
        // }

        int oneConutb = 0, oneConuta = 0;
        for (int i = 0; i < n; i++)
        {
            oneConutb += (b[i] == '1');
            oneConuta += (a[i] == '1');
        }

        if (oneConutb == 0)
        {
            out(true);
            continue;
        }

        if (oneConuta == 0)
        {
            out(false);
            continue;
        }
        bool valid = true;

        

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
#define f first
#define s second
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
        string a, b;
        cin >> a >> b;

        // if (n == 2)
        // {
        //     if (a == b || b == "00")
        //         out(true);
        //     else
        //         out(false);
        //     continue;
        // }

        int oneConutb = 0, oneConuta = 0;
        for (int i = 0; i < n; i++)
        {
            oneConutb += (b[i] == '1');
            oneConuta += (a[i] == '1');
        }

        if (oneConutb == 0)
        {
            out(true);
            continue;
        }

        if (oneConuta == 0)
        {
            out(false);
            continue;
        }

        vector<string> groups;

        int zeroCount = 0, len = 0;
        string smalla = "", smallb = "";
        bool valid = true, isonea = false, iszero = false, isPending = false;

        for (int i = 0; i < n; i++)
        {

            if (b[i] == '0')
            {
                len++;
                if (a[i] == '1')
                    isonea = true;
                if (i + 1 < n && b[i] == '0')
                    continue;
                if (i - 1 >= 0 && b[i] == '0')
                    continue;
                if (a[i] == '0')
                {
                    //  0
                    // 101
                    if (isPending && !isonea)
                    {
                        valid = false;
                        break;
                    }
                    isPending = false;
                    isonea = false;
                    len = 0;
                    continue;
                }
                //  1
                // 101

                valid = false;
                break;
            }
            else
            {
                //  0
                // .1.

                //  1
                // .1.
                len++;
                if (a[i] == b[i])
                    continue;
                else if (!isonea)
                    isPending = true;
            }
        }

        out(valid);
    }
    return 0;
}
*/
/*
100000
111010
*/