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

int32_t main()
{
    string s;
    cin >> s;

    int ma = 0, n = s.size();
    char ch;
    map<char, int> f;
    for(auto e : s) {
        f[e]++;
        ma = max(ma, f[e]);
        if(ma == f[e])
            ch = e;
    }

    if(ma > (n+1)/2)
    {
        cout << "-1";
        return 0;
    }

    string ans(n, ' ');
    if(n%2 && ma == (n+1) / 2) {
        for(int i = 0; i < n; i += 2) {
            ans[i] = ch;
            f[ch]--;
        }
    }

    int i = 0, j = 0;
    sort(s.begin(), s.end());
    while(i < n) {
        if(f[s[j]] == 0) {
            j++;
            continue;
        }
        if(ans[i] != ' ') {
            i += 2;
            continue;
        }
        ans[i] = s[j];
        f[s[j]]--;
        j++;
        i+=2;
    }

    i = 1;
    while(i < n) {
        if(f[s[j]] == 0) {
            j++;
            continue;
        }
        if(ans[i] != ' ') {
            i += 2;
            continue;
        }
        ans[i] = s[j];
        f[s[j]]--;
        j++;
        i+=2;
    }

    cout << s;
    return 0;
}

/*

HATTIVATTI
AAHIITTTTV

AHATITITVT


*/