class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> v;
        int cnt = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt += s[i] == '1' ? 1 : -1;

            if (cnt == 0) {
                string inside = s.substr(start + 1, i - start - 1);
                v.push_back("1" + makeLargestSpecial(inside) + "0");
                start = i + 1;
            }
        }
        sort(v.rbegin(), v.rend());
        string ans;
        for (auto x : v)
            ans += x;

        return ans;
    }
};