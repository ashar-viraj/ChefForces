// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// Driver code
int main()
{
     ordered_multiset s;
     int n, k;
     cin >> n >> k;

     for (int i = 1; i <= n; i++)
          s.insert(i);

     int ind = k % n;
     while (n--)
     {
          auto itr = s.find_by_order(ind);
          cout << *itr << ' ';
          s.erase(itr);
          if (n)
               ind = (ind % n + k) % n;
     }
     return 0;
}
