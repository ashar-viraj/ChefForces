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
#define pb push_back
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int findSteps(int h)
{
    int steps = (-1 + sqrt(1 + 8 * h)) / 2;

    if ((steps * (steps + 1)) / 2 == h)
        steps--;
    return steps;
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
        int h, d;
        cin >> h >> d;
        // int h = 999961560, d = 1000000000;

        int curr = 0, turn = 0;
        bool rest = false;
        while (curr != d)
        {
            int steps = findSteps(h);
            if (rest)
            {
                if (h <= 2)
                    break;
                h++;
                turn++;
                rest = false;
            }
            else
            {
                h -= (steps * (steps + 1)) / 2;

                int stepsReq = (d - curr);

                curr += steps;
                if (stepsReq <= steps)
                    turn += stepsReq;
                else
                    turn += steps;

                rest = true;
            }

            curr = min(curr, d);
        }

        if (curr != d)
            turn += (d - curr) * 2;

        cout << turn << endl;
    }
    return 0;
}