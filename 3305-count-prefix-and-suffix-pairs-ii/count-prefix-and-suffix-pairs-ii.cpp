class Solution {
public:
    struct Node {
        unordered_map<int,int> next;
        long long cnt = 0;
    };
    long long countPrefixSuffixPairs(vector<string>& words) {
        vector<Node> trie(1);
        long long ans = 0;
        for (string &s : words) {
            int node = 0, n = s.size();

            for (int i = 0; i < n; i++) {
                int key = (s[i] - 'a') * 26 + s[n - 1 - i] - 'a';

                if (!trie[node].next.count(key)) {
                    trie[node].next[key] = trie.size();
                    trie.emplace_back();
                }
                node = trie[node].next[key];
                ans += trie[node].cnt;
            }

            trie[node].cnt++;
        }
        return ans;
    }
};