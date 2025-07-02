#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, d, j;
    map<int, int> primes;
    for(i = 0; i < 1000000; i++)
    {
        if(isPrime(i))
        {
            primes[i]++;
        }
    }
    cin >> t;
    while (t--)
    {
        int j = 0;
        cin >> n;
        vector<int> pairNumbers;
        unordered_map<int, int> m;
        for (i = 1; i <= n; i++)
        {
            if (primes[i])
            {
                pairNumbers.push_back(i);
                j++;
                m[i]++;
            }
        }
        // cout << pairNumbers.size() << "\n";
        int a = 2;
        int count = 0;
        for (i = 5; i < pairNumbers.size() - 1; i++)
        {
            if (prime(i) )
            {
                if(i-a == 2)
                {

                }
                count++;
                a = i;   
            }
        }
        cout << count << "\n";
    }
    return 0;
}