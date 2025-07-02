#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007

class Solution
{
public:
    double distance(double i, double j, double x, double y)
    {
        return sqrt(pow(i - x, 2) + pow(j - y, 2));
    }

    int countLatticePoints(vector<vector<int>> &circles)
    {
        unordered_map<int, unordered_map<int, bool>> m;

        for (int i = 0; i < circles.size(); i++)
        {
            for (int j = circles[i][0] - circles[i][2]; j <= circles[i][0] + circles[i][2]; j++)
            {
                for (int k = circles[i][1] - circles[i][2]; k <= circles[i][1] + circles[i][2]; k++)
                {
                    if (distance(j, k, circles[i][0], circles[i][1] <= circles[i][2]))
                    {
                        m[j][k] = true;
                    }
                }
            }
        }
        int ans = 0;
        for (auto e : m)
        {
            ans += e.second.size();
        }

        return ans;
    }
};

int32_t main()
{

    return 0;
}