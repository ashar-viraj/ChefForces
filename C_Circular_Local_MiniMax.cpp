#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define um unordered_map
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

class Solution
{
public:
    bool canMeasureWater(int a, int b, int k)
    {
        unordered_map<int, unordered_map<int, bool>> visited;

        int x = 0, y = 0;
        visited[x][y] = true;

        queue<int> qx, qy;
        qx.push(a), qy.push(b);
        qx.push(0), qy.push(0);
        visited[0][0] = true;
        visited[a][b] = true;

        while (qx.size())
        {
            int x = qx.front(), y = qy.front();
            qx.pop(), qy.pop();
            if (x + y == k || x == k || y == k)
                return true;
            int newx, newy;

            // fill a from b
            int reqa = a - x;
            if (reqa >= y)
            {
                if (!visited[x + y][0])
                {
                    visited[x + y][0] = true;
                    qx.push(x + y), qy.push(0);
                }
            }
            else
            {
                if (!visited[a][y - reqa])
                {
                    visited[a][y - reqa] = true;
                    qx.push(a), qy.push(y - reqa);
                }
            }

            int reqb = b - y;
            if (reqb >= x)
            {
                if (!visited[0][x + y])
                {
                    visited[0][x + y] = true;
                    qx.push(0), qy.push(x + y);
                }
            }
            else
            {
                if (!visited[x - reqb][b])
                {
                    visited[x - reqb][b] = true;
                    qx.push(x - reqb), qy.push(b);
                }
            }

            // fill a full
            if (!visited[a][y])
            {
                visited[a][y] = true;
                qx.push(a), qy.push(y);
            }

            // fill b full
            if (!visited[x][b])
            {
                visited[x][b] = true;
                qx.push(x), qy.push(b);
            }
            // empty a full
            if (!visited[0][y])
            {
                visited[0][y] = true;
                qx.push(0), qy.push(y);
            }

            // empty b full
            if (!visited[x][0])
            {
                visited[x][0] = true;
                qx.push(x), qy.push(0);
            }
        }
        return false;
    }
};

int32_t main()
{
    Solution ob;
    cout << ob.canMeasureWater(3, 5, 4) << endl;
    return 0;
}