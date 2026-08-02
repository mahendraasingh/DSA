class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> m1;
        unordered_set<int> m2;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            m1.insert(nums1[i]);
        }
        for (int j = 0; j < nums2.size(); j++) {
            m2.insert(nums2[j]);
        }
        for (auto x : m1) {
            if (m2.find(x) != m2.end()) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};