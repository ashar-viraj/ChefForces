// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    int lps(string s)
    {
        int ep = s.size() - 2, es = s.size() - 1, length = 0, temp = ep;
        while (true)
        {
            // tmmzztmmz
            // 012345678
            if (ep == -1)
            {
                break;
            }
            // cout << "ep : " << ep << ", es = " << es << "\n";
            if (s[ep] == s[es])
            {
                length++;
                es--;
            }
            else
            {
                length = 0;
                temp--;
                ep = temp + 1;
                es = s.size() - 1;
            }
            ep--;
        }
        return length;
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
} // } Driver Code Ends