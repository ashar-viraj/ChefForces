#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

class Solution
{
public:
    int sum(int n)
    {
        int total = 0;
        while (n)
        {
            total += n % 10;
            n /= 10;
        }

        return total;
    }

    long long makeIntegerBeautiful(long long n, int target)
    {
        int ans = n, place = 100;
        while (ans % 10 && sum(ans) > target)
        {
            ans++;
        }
        string temp;
        while (sum(ans) > target)
        {
            ans += place/10;
            if ((ans / place) * place == ans)
                place *= 10;
            cout << ans << ' ' << place;
            cin >> temp;
        }

        return ans - n;
    }
};

int main()
{
    Solution obj;
    cout << obj.makeIntegerBeautiful(501, 1) << endl;
    return 0;
}