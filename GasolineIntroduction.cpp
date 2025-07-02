#include <bits/stdc++.h>
using namespace std;

int gasolineIntroduction(vector<int> pump, int N)
{
    int i, distance = 0, fuel = pump[0];
    for (i = 1; i < N; i++)
    {
        distance++;
        fuel--;
        fuel += pump[i];
        if (fuel == 0)
        {
            break;
        }
    }
    if (fuel != 0)
    {
        distance += fuel;
    }
    return distance;
}

int main()
{
    int T, i, N, temp;
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<int> pump;
        for (i = 0; i < N; i++)
        {
            cin >> temp;
            pump.push_back(temp);
        }
        cout << gasolineIntroduction(pump, N) << "\n";
    }
    return 0;
}