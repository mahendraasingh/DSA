class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for(int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for(string word : words) {

            int prev = -1;
            bool possible = true;

            for(char ch : word) {
                auto it = upper_bound(
                    pos[ch - 'a'].begin(),
                    pos[ch - 'a'].end(),
                    prev
                );

                if(it == pos[ch - 'a'].end()) {
                    possible = false;
                    break;
                }
                prev = *it;
            }
            if(possible) {
                ans++;
            }
        }
        return ans;
    }
};