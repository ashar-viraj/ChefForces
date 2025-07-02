#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

/*
chance = 0(Taro)
chance = 1(Jiro)
*/

pair<int, int> solve(vector<int> &v, int i, int j, int chance, vector<vector<vector<pair<int, int>>>> &dp, vector<vector<vector<bool>>> &done)
{
    if (i > j)
        return {0, 0};

    if (done[i][j][chance])
        return dp[i][j][chance];

    pair<int, int> leftAns = solve(v, i, j - 1, chance ^ 1, dp, done);
    pair<int, int> rightAns = solve(v, i + 1, j, chance ^ 1, dp, done);
    pair<int, int> ans;

    if (chance == 0)
    {
        if ((leftAns.first + v[j] - leftAns.second) > (rightAns.first + v[i] - rightAns.second))
            ans = {leftAns.first + v[j], leftAns.second};
        else
            ans = {rightAns.first + v[i], rightAns.second};
    }
    else
    {
        if ((leftAns.first - leftAns.second - v[j]) < (rightAns.first - rightAns.second - v[i]))
            ans = {leftAns.first, leftAns.second + v[j]};
        else
            ans = {rightAns.first, rightAns.second + v[i]};
    }

    done[i][j][chance] = true;

    return dp[i][j][chance] = ans;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, pair<int, int>({0, 0})));

    int taroChance = (n - 1) % 2;

    for (int k = 0; k < n; k++)
    {
        if (taroChance == 0)
            dp[k][k] = {v[k], 0};
        else
            dp[k][k] = {0, v[k]};
    }

    for (int k = 1; k < n; k++)
    {
        int i = 0, j = k;
        while (i < n && j < n)
        {
            int range = (j - i);

            if ((range % 2) == taroChance)
            {
                if ((dp[i][j - 1].first + v[j] - dp[i][j - 1].second) > (dp[i + 1][j].first + v[i] - dp[i + 1][j].second))
                    dp[i][j] = {dp[i][j - 1].first + v[j], dp[i][j - 1].second};
                else
                    dp[i][j] = {dp[i + 1][j].first + v[i], dp[i + 1][j].second};
            }
            else
            {
                if ((dp[i][j - 1].first - dp[i][j - 1].second - v[j]) < (dp[i + 1][j].first - dp[i + 1][j].second - v[i]))
                    dp[i][j] = {dp[i][j - 1].first, dp[i][j - 1].second + v[j]};
                else
                    dp[i][j] = {dp[i + 1][j].first, dp[i + 1][j].second + v[i]};
            }
            i++, j++;
        }
    }


    cout << dp[0][n - 1].first - dp[0][n - 1].second << endl;

    return 0;
}