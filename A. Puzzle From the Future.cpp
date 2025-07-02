#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, temp, d;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        string ans = "1";
        for (i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                if (ans[i - 1] == '0')
                {
                    ans += '1';
                }
                else
                {
                    ans += '0';
                }
            }
            else
            {
                if ((ans[i - 1] == '0' && s[i - 1] == '0') ||
                    (ans[i - 1] == '1' && s[i - 1] == '0') ||
                    (ans[i - 1] == '1' && s[i - 1] == '1'))
                {
                    ans += '1';
                }
                else
                {
                    ans += '0';
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}