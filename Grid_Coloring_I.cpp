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
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

char replace(char c1, char c2, char c3) {
    for(char ch = 'A'; ch <= 'D'; ch++)
        if(ch != c1 && ch != c2 && ch != c3)
            return ch;

    return 'D';
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    vector<string> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    v[0][0] = replace(v[0][0], v[0][0], v[0][0]);

    for(int j = 1; j < m; j++)
        v[0][j] = replace(v[0][j-1], v[0][j], v[0][j]);

    for(int i = 1; i < n; i++) {
        v[i][0] = replace(v[i][0], v[i-1][0], v[i-1][0]);
        for(int j = 1; j < m; j++) {
            v[i][j] = replace(v[i][j], v[i-1][j], v[i][j-1]);
        }
    }

    for(auto row: v) {
        for(auto e: row)
            cout << e;
        cout << endl;
    }

    return 0;
}