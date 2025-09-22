#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
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
const int x8[8] = {-1, -2, -2, -1, 1, 2, 2, 1}, y8[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int32_t main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, -1));
    queue<int> qx, qy;

    v[0][0] = 0;
    qx.push(0);
    qy.push(0);

    while(qx.size()) {
        int x = qx.front(), y = qy.front();
        qx.pop(), qy.pop();

        for(int k = 0; k < 8; k++) {
            int i = x + x8[k], j = y + y8[k];

            if(i >= 0 && i < n && j >= 0 && j < n && v[i][j] == -1) {
                v[i][j] = v[x][y] + 1;
                qx.push(i);
                qy.push(j);
            }
        }
    }

    for(auto r : v) {
        for(auto c: r) {
            cout << c << ' ';
        }

        cout << endl;
    }
    return 0;
}