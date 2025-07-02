#include <bits/stdc++.h>
using namespace std;

bool isprime(long long int n)
{
    for (long long int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void NumberIntoSequence(long long int n)
{
    if (isprime(n))
    {
        cout << "1\n"
             << n;
        return;
    }
    vector<long long int> primeFactors;
    map<long long int, int> frequency;
    for (long long int i = 2; i <= n / 2; i++)
    {
        if (n % i != 0)
            continue;
        if (!isprime(i))
        {
            continue;
        }
        primeFactors.push_back(i);
    }

    long long int tempN = n;
    for (int i = 0; i < primeFactors.size(); i++)
    {
        while (tempN % primeFactors[i] == 0)
        {
            if (tempN % primeFactors[i] == 0)
                frequency[primeFactors[i]]++;
            tempN /= primeFactors[i];
        }
    }
    long long int max = 0;
    int times = 0;

    for (auto i : frequency)
    {
        if (i.second > times)
        {
            max = i.first;
            times = i.second;
        }
    }
    cout << times << "\n";
    for (int i = 1; i < times; i++)
    {
        cout << max << " ";
    }
    cout << n / pow(max, times - 1);
}

int main()
{
    int T, i;
    long long int N;
    cin >> T;
    while (T--)
    {
        cout << "Input a number:";
        cin >> N;
        NumberIntoSequence(N);
        cout << "\n";
    }
    return 0;
}