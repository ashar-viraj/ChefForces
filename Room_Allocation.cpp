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

struct Compare
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first;
    }
};

int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> cus(n, vector<int>(3));
    rep(i, 0, n)
    {
        cin >> cus[i][0] >> cus[i][1];
        cus[i][2] = i;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int roomReq = 0;

    sort(cus.begin(), cus.end());

    // for (auto e : cus)
    //     cout << e[0] << ' ' << e[1] << ' ' << e[2] << endl;
    // cout << endl;

    for (int i = 0; i < n; i++)
    {
        while (pq.size() && pq.top() < cus[i][0])
            pq.pop();
        pq.push(cus[i][1]);

        roomReq = max(roomReq, (int)pq.size());
    }

    queue<int> availRooms;
    while (pq.size())
        pq.pop();

    for (int i = 1; i <= roomReq; i++)
        availRooms.push(i);
    vector<int> ans(n);

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> assignedRooms;

    for (int i = 0; i < n; i++)
    {
        while (assignedRooms.size() && assignedRooms.top().f <= cus[i][0])
        {
            availRooms.push(assignedRooms.top().s);
            assignedRooms.pop();
        }

        ans[cus[i][2]] = availRooms.front();
        assignedRooms.push({cus[i][1], availRooms.front()});
        availRooms.pop();
    }

    cout << roomReq << endl;
    for (auto e : ans)
        cout << e << ' ';

    return 0;
}