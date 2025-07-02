/* Time complexity: O(N*M) Space complexity: O(N) where N is the number of vertex and M is the number of edges */
#include <bits / stdc++.h>
using namespace std;
class edge
{
public:
    int a, b, cost;
    edge(int a, int b, int cost)
    {
        this->a = a;
        this->b = b;
        this->cost = cost;
    }
};
const int INF = 1e9;
int solve(vector<edge> &e, int n, int m, int src, int des)
{
    vector<int> d(n + 1, INF);
    d[src] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (d[e[j].a] < INF)
            {
                d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].cost);
            }
        }
    }
    return d[des];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int src, des;
        cin >> src >> des;
        vector<edge> e;
        for (int i = 0; i < m; i++)
        {
            int a, b, cost;
            cin >> a >> b >> cost;
            e.push_back(edge(a, b, cost));
        }
        int ans = solve(e, n, m, src, des);
        cout << ans << endl;
    }
}
/*
["WordFilter","f","f","f","f","f","f","f","f","f","f"]
cabaabaaaa  cabaabaaaa
ccbcababac  ccbcababac
bacaabccba  bacaabccba
bcbbcbacaa  bcbbcbacaa
abcaccbcaa  abcaccbcaa
accabaccaa  accabaccaa
cabcbbbcca  cabcbbbcca
ababccabcb  ababccabcb
caccbbcbab  caccbbcbab
bccbacbcba  bccbacbcba

bccbacbcba           a
ab          abcaccbcaa
a                   aa
cabaaba         abaaaa
cacc         accbbcbab
ccbcab             bac
bac                cba
ac          accabaccaa
bcbb                aa
ccbca        cbcababac
*/