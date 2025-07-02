// #include <bits/stdc++.h>
// using namespace std;

// bool isPrime(int64_t n) 
// { 
//     // Corner cases 
//     if (n <= 1) 
//         return false; 
//     if (n < 3) 
//         return false; 
//     if(n%2==0)
//     {
//         if((n/2)%2)
//         {
//             return true;
//         }
//     }
//     if(n%4==0)
//     {
//         if((n/4)%4)
//         {
//             return true;
//         }
//     }
//     // This is checked so that we can skip 
//     // middle five numbers in below loop 
//     if (n % 3 == 0 || n %5 == 0) 
//         return true; 
//     for (int64_t i = 5; i * i <= n; i = i + 6) 
//     {
//         if (n % i == 0 ) 
//         {
//             if((n/i)%2 == 1)
//             {
//                 return true;
//             }
//             if(i%2 == 1)
//                 return true;
//         }
//         if(n % (i + 2) == 0)
//         {
//             if(n/(i+2)%2 || (i+2)%2==1)
//             {
//                 return true;
//             }
//         }
//     }
    
//     return false; 
// } 

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int64_t t, i, n, temp, d;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         bool valid = isPrime(n);
//         if (valid)
//         {
//             cout << "YES\n";
//         }
//         else
//         {
//             cout << "NO\n";
//         }
//     }
    
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

bool isPrime(int64_t n) 
{ 
    // Corner cases 
    if(n%2)
    {
        return true;
    }
    if (n <= 1) 
        return false; 
    if (n < 3) 
        return false; 
    if(n%2==0)
    {
        if((n/2)%2)
        {
            return true;
        }
    }
    if(n%4==0)
    {
        if((n/4)%2)
        {
            return true;
        }
    }
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 3 == 0 || n %5 == 0) 
        return true; 
    for (int64_t i = 5; i * i <= n; i = i + 6) 
    {
        if (n % i == 0 ) 
        {
            if((n/i)%2 == 1)
            {
                return true;
            }
            if(i%2 == 1)
                return true;
        }
        if(n % (i + 2) == 0)
        {
            if(n/(i+2)%2 || (i+2)%2==1)
            {
                return true;
            }
        }
    }
    
    return false; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int64_t t, i, n, temp, d;
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool valid = isPrime(n);
        if (valid)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    
    return 0;
}