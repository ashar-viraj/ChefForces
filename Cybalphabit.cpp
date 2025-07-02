#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, k, itemp;
    vector<pair<char, int>> latinPairs;
    for (i = 0; i < 26; i++)
    {
        latinPairs.push_back(make_pair((char)i + 97, pow(2, i)));
    }
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        string x = "";
        if (k < n)
        {
            cout << "-1\n";
            continue;
        }
        else if (k == n)
        {
            for (i = 0; i < k; i++)
            {
                x += 'a';
            }
            cout << x << "\n";
            continue;
        }
        int arr[n], required = k - n, start = n - 1;
        for (i = 0; i < n; i++)
        {
            arr[i] = 1;
        }
        while (true)
        {
            if (required == 0 || start == -1)
            {
                break;
            }
            itemp = pow(2, (int)log2(required + 1));
            arr[start] = pow(2, (int)log2(required + 1));
            required -= (itemp - 1);
            start--;
        }
        for (i = 0; i < n; i++)
        {
            x += latinPairs[log2(arr[i])].first;
        }
        if (required != 0)
        {
            cout << "-1\n";
            continue;
        }
        cout << x << "\n";
    }
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

string convertToBinary(int N)
{
    long long int B_Number = 0;
    int cnt = 0;
    while (N != 0)
    {
        int rem = N % 2;
        long long int c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;

        // Count used to store exponent value
        cnt++;
    }

    return to_string(B_Number);
}

int main()
{
    int t, i, n, k;
    vector<pair<char, int>> latinPairs;

    for (i = 0; i < 26; i++)
    {
        latinPairs.push_back(make_pair((char)i + 97, pow(2, i)));
    }
    // for (auto itr = latinPairs.begin(); itr != latinPairs.end(); itr++)
    // {
    //     cout << itr->first << " " << itr->second << "\n";
    // }
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        string binary = convertToBinary(k), x = "";
        int count = 0;
        for(i = 0; i < binary.size(); i++)
        {
            if(binary[i] == '1')
            {
                count++;
            }
        }
        if(count > n || k < n)
        {
            cout << "-1\n";
            continue;
        }
        else if(k == n)
        {
            for(i = 0; i < k; i++)
            {
                x+='a';
            }
            cout << x << "\n";
            continue;
        }
        else
        {
            int start;
            for(i = 25; i >= 0; i--)
            {
                if()
            }

            
        }
    }

    while (t--)
    {
        int start, i = 25;
        for (auto itr = latinPairs.size() - 1; itr >= 0; itr--)
        {
            if (k <= latinPairs[itr].second)
            {
                start = itr;
                break;
            }
        }
        int sum = k;
        do
        {
            if (n == sum)
            {
                x += 'a';
                n--;
                sum--;
                continue;
            }
            else if (sum < latinPairs[i].second)
            {
                while (latinPairs[i].second > sum)
                {
                    i--;
                }
                x += latinPairs[i].first;
                sum--;
                n--;
            }
            else
            {
            }
            

            cout << "i = " << i << latinPairs[i].first << "\n";
            x += latinPairs[i].first;
            sum -= latinPairs[i].second;
        } while (n--);
        cout << "\n"
             << x << "\n\n";  
    }
    

    return 0;
}
*/