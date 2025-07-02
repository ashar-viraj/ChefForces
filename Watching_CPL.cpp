#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, h, temp;
    cin >> t;
    while (t--)
    {
        cin >> n >> h;
        vector<int> box;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            box.push_back(temp);
        }
        sort(box.begin(), box.end());
        reverse(box.begin(), box.end());
        int sum = box[0], count = -1;
        unordered_set<int> subset;
        subset.insert(box[0]);
        for (i = 1; i < n; i++)
        {
            sum += box[i];
            unordered_set<int> ustemp;
            auto itr = subset.begin();
            while (true)
            {
                if (itr == subset.end())
                {
                    break;
                }
                int itemp = *itr;
                ustemp.insert(box[i]);
                ustemp.insert(box[i] + *itr);
                ustemp.insert(*itr);
                if (((itemp + box[i]) >= h && (sum - (itemp + box[i])) >= h) ||
                    (box[i] >= h && sum - box[i] >= h))
                {
                    count = i + 1;
                    break;
                }
                itr++;
            }
            if (count != -1)
            {
                break;
            }
            subset = ustemp;
        }
        cout << count << "\n";
    }
    return 0;
}
