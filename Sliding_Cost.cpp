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
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &e : v)
        cin >> e;

    vector<int> ans;
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            cout << "0 ";
        return 0;
    }
    if (k == 2)
    {
        for (int i = 1; i < n; i++)
            cout << abs(v[i] - v[i - 1]) << ' ';
        return 0;
    }

    multiset<int> left, right;
    int n1 = (k + 1) / 2, n2 = k - n1, leftSum = 0, rightSum = 0;
    int i = 0, j = 0;
    while (j < k)
        left.insert(v[j++]);

    while (left.size() != n1)
    {
        right.insert(*left.rbegin());
        left.erase(left.find(*left.rbegin()));
    }

    for (auto e : left)
        leftSum += e;
    for (auto e : right)
        rightSum += e;

    int smallAns, mustLeft, mustRight;
    mustLeft = *left.rbegin() * n1;
    mustRight = *left.rbegin() * n2;
    smallAns = mustLeft - leftSum + rightSum - mustRight;
    ans.push_back(smallAns);

    while (j < n)
    {
        if (left.find(v[i]) != left.end())
        {
            left.erase(left.find(v[i]));
            leftSum -= v[i];
        }
        else
        {
            right.erase(right.find(v[i]));
            rightSum -= v[i];
        }
        i++;

        if (v[j] > *left.rbegin())
        {
            right.insert(v[j]);
            rightSum += v[j];
        }
        else
        {
            left.insert(v[j]);
            leftSum += v[j];
        }
        j++;

        if (left.size() > n1)
        {
            right.insert(*left.rbegin());
            rightSum += *left.rbegin();
            leftSum -= *left.rbegin();
            left.erase(left.find(*left.rbegin()));
        }
        else if (left.size() < n1)
        {
            left.insert(*right.begin());
            leftSum += *right.begin();
            rightSum -= *right.begin();
            right.erase(right.find(*right.begin()));
        }

        mustLeft = *left.rbegin() * n1;
        mustRight = *left.rbegin() * n2;
        smallAns = mustLeft - leftSum + rightSum - mustRight;
        ans.push_back(smallAns);
    }

    // cout << endl;
    for (auto e : ans)
        cout << e << ' ';

    return 0;
}