#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <algorithm>
#include <queue>
using namespace std;

const int mod = 1e9 + 7;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void add_self(int &a, int b)
{
    a += b;

    if (a >= mod)
        a -= mod;
}

int subarraysWithKDistinct(vector<int> &nums, int k, int r)
{
    // Array to store the count of distinct values encountered
    vector<int> distinctCount(nums.size() + 1, 0);

    int totalCount = 0;
    int left = 0;
    int right = 0;
    int currCount = 0;

    while (right < nums.size())
    {
        // Increment the count of the current element in the window
        if (++distinctCount[nums[right++]] == 1)
        {
            // If encountering a new distinct element, decrement K
            k--;
        }

        // If K becomes negative, adjust the window from the left
        if (k < 0 || (right - left + 1) > r)
        {
            // Move the left pointer until the count of distinct elements
            // becomes valid again
            --distinctCount[nums[left++]];
            k++;
            currCount = 0;
        }

        // If K becomes zero, calculate subarrays
        if (k == 0)
        {
            // While the count of left remains greater than 1, keep
            // shrinking the window from the left
            while (distinctCount[nums[left]] > 1)
            {
                --distinctCount[nums[left++]];
                currCount++;
            }
            // Add the count of subarrays with k distinct elements to the
            // total count

            totalCount += (currCount + 1);
        }
    }
    return totalCount;
}
void solve()
{
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> nums(n);
    for (int &x : nums)
        cin >> x;
    cout << subarraysWithKDistinct(nums, k, r) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}