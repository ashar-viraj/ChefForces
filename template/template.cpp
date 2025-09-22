const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}



vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}



//Floyd warshall
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}



//Rabin karp
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}






//Segment tree

template <typename T>
struct segTree // 1-based indexing.
{
    int size, n;
    vector<T> st, arr;

    segTree(int sizeOfTree)
    {
        n = sizeOfTree;
        arr.resize(n + 1);
        size = 1;
        while (size < sizeOfTree)
            size <<= 1;

        size <<= 1;
        st.resize(size + 1);
    }

    void set(int si, int ss, int se, int idx, T val)
    {
        if (ss == se)
        {
            st[si] = val;
            arr[idx] = val;
            return;
        }

        int mid = (ss + se) / 2;

        if (idx <= mid)
            set(2 * si, ss, mid, idx, val);
        else
            set(2 * si + 1, mid + 1, se, idx, val);

        st[si] = combine(st[2 * si], st[2 * si + 1]);
    }

    T query(int si, int ss, int se, int l, int r)
    {
        if (ss > r || se < l)
            return 0;                   // Handle it according to problem

        if (l <= ss && r >= se)
            return st[si];

        int mid = (ss + se) / 2;

        T left = query(2 * si, ss, mid, l, r);
        T right = query(2 * si + 1, mid + 1, se, l, r);

        return combine(left, right);
    }

    T combine(T x, T y)                 // Handle it according to problem
    {
        return x + y;
    }

    void set(int idx, T val)
    {
        set(1, 1, n, idx, val);
    }

    T query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }
};