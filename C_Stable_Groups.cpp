#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

bool prime[100001];

void SieveOfEratosthenes(int n = 100000)
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, x, i, j, n, itemp, k, groups = 1;
    cin >> n >> k >> x;
    int Students[n];
    vector<int> RequiredStudents;
    rep(i, 0, n)
        cin >> Students[i];
    sort(Students, Students + n);
    rep(i, 0, n - 1)
    {
        if (abs(Students[i] - Students[i + 1]) > (int)x)
        {
            int req = Students[i + 1] - Students[i];
            itemp = req/x;
            if(itemp*x == req)
                req = itemp-1;
            else
                req = itemp;
            RequiredStudents.push_back(req);
            groups++;
        }
    }
    int count = 0, groupsJoined = 0;
    i = 0;
    sort(RequiredStudents.begin(), RequiredStudents.end()); 
    while(count <= k && i < RequiredStudents.size())
    {
        if(count + RequiredStudents[i] <= k)
        {
            count += RequiredStudents[i];
            i++;
            groupsJoined++;
            continue;
        }
        break;
    }
    // cout << RequiredStudents.size() << " " << groupsJoined << endl;
    cout << RequiredStudents.size() + 1 - groupsJoined;

    return 0;
}

/*
23 8 2
1 3 4 11 13 14 17 22 23 25 34 36 39 40 51 53 59 63 65 67 76 77 79
*/