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

bool solve2(vector<vector<int>> preans, vector<vector<int>> vans, vector<vector<int>> postans, int x)
{
    vector<vector<int>> final;
    int ans = 0;
    ans = 0;
    for (auto e : preans)
    {
        final.push_back({1, ans, e[2]});
        cout << e[2] << ' ';
        ans |= e[2];
    }
    cout << "|" << ans << endl;

    int i;
    for (int i = 0; i < vans.size(); i++)
    {
        final.push_back({vans[i][0], ans, vans[i][2]});
        ans ^= vans[i][2];
        cout << vans[i][2] << ' ';
    }
    cout << "|" << ans << endl;

    for (auto e : postans)
    {
        final.push_back({1, ans, e[2]});
        ans |= e[2];
        cout << e[2] << ' ';
    }
    cout << "|" << ans << endl;

    if (ans != x)
    {
        return false;
    }

    for (int i = 1; i < final.size(); i++)
    {
        cout << final[i][0] << ' ' << final[i][1] << ' ' << final[i][2] << endl;
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int x;
        cin >> n >> x;
        unordered_map<int, bool> orbits, xor2bits;

        int bit = 15;

        while (bit >= 0)
        {
            if (((1 << bit) & x) && ((1 << bit) <= n))
                orbits[1 << bit] = true;
            if (((1 << bit) ^ x) && ((1 << bit) <= n))
                xor2bits[1 << bit] = true;
            bit--;
        }

        vector<vector<int>> vans;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (orbits[i] || xor2bits[i])
                continue;
            if (vans.size() == 0)
            {
                ans = i;
                vans.push_back({2, ans, ans});
            }
            else
            {
                vans.push_back({2, ans, i});
                ans ^= i;
            }
        }

        vector<vector<int>> preans;
        vector<vector<int>> postans;

        bit = 15;

        cout << "Ans : " << ans << endl;

        while (bit >= 0)
        {
            if (orbits[(1 << bit)])
            {
                postans.push_back({1, ans, (1 << bit)});
            }
            else if (xor2bits[(1 << bit)])
            {
                if (ans ^ (1 << bit))
                {
                    vans.push_back({1, 0, (1 << bit)});
                }
                else
                {
                    vans.push_back({2, 0, (1 << bit)});
                }
            }
            bit--;
        }

        vector<vector<int>> final;

        bool ansExist = false;
        ans = 0;
        for (auto e : preans)
        {
            final.push_back({1, ans, e[2]});
            ans |= e[2];
        }

        int i;
        for (int i = 0; i < vans.size(); i++)
        {
            if (i == 0)
            {
                final.push_back({1, ans, vans[i][2]});
                ans |= vans[i][2];
            }
            else
            {
                if (vans[i][0] == 1)
                {
                    final.push_back({vans[i][0], ans, vans[i][2]});
                    ans |= vans[i][2];
                }
                else
                {
                    final.push_back({vans[i][0], ans, vans[i][2]});
                    ans ^= vans[i][2];
                }
            }
        }

        for (auto e : postans)
        {
            final.push_back({1, ans, e[2]});
            ans |= e[2];
        }

        // cout << "ans : " << ans << endl;
        if (ans != x)
        {
            cout << "\npreans";
            for (auto e : preans)
                cout << e[2] << ' ';
            cout << "\nvans";
            for (auto e : vans)
                cout << e[2] << ' ';
            cout << "\npostans";
            for (auto e : postans)
                cout << e[2] << ' ';
            // for (auto e : final)
            //     cout << e[0] << ' ' << e[1] << ' ' << e[2] << endl;

            // bool checkAnother = solve2(preans, vans, postans, x);

            // if (!checkAnother)
            cout << "-1\n";
            continue;
        }

        for (int i = 1; i < final.size(); i++)
        {
            cout << final[i][0] << ' ' << final[i][1] << ' ' << final[i][2] << endl;
        }
    }
    return 0;
}