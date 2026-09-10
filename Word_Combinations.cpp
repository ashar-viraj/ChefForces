#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
#define f first
#define s second
#define pb push_back
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

class Trie{
public:
    char ch;
    map<char, Trie*> childs;
    bool isWord;
};

void addWord(Trie *node, string &word, int i, int n) {
    if(i == n) {
        node->isWord = true;
        return;
    }

    if(!node->childs[word[i]]) {
        Trie *newNode = new Trie();
        newNode->ch = word[i];
        node->childs[word[i]] = newNode;
    }

    addWord(node->childs[word[i]], word, i+1, n);
}

void printTrie(Trie *root, int level) {
    cout << root->ch << ' ' << level << ' ' << root->isWord << endl;
    for(auto e : root->childs)
        printTrie(e.second, level+1);
}

int32_t main()
{
    string s;
    Trie *root = new Trie();

    int n, m;
    cin >> s >> m;
    map<string, bool> isThere;
    string word;
    for(int i = 0; i < m; i++)
    {
        cin >> word;
        addWord(root, word, 0, word.size());
    }

    n = s.size();
    vector<int> dp(n+1, 0);
    dp[n] = 1;


    for(int i = n-1; i >= 0; i--) {
        Trie *curr = root->childs[s[i]];
        for(int j = i; j < n && curr; j++, curr = curr->childs[s[j]]) {
            if(curr->isWord)
                (dp[i] += dp[j+1]) %= MOD;
        }
    }

    cout << dp[0];
    return 0;
}