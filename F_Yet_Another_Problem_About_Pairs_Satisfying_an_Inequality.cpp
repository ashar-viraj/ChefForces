#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n' 
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int merge(vector<int> &v, int s, int e, int mid)
{

    vector<int> newv(e-s+1);

    int i = 0, j = mid+1, k;
    while(i <= mid && j <= e)
    {
        
    }

}
/*
0 2 1 6 3 4 1 2 8 3
0 1 1 2 2 3 3 4 6 8
*/
int solve(vector<int> &v, int s, int e)
{
    if(s == e)
    {
        return 0;
    }

    int mid = (s+e) / 2;
    int leftAns = solve(v, s, mid);
    int rightAns = solve(v, mid+1, e);



}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> v(n);
        rep(i, 0, n)
        {
            cin >> v[i];
        }

    }
    return 0;
}