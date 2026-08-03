class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans1;
        vector<int> ans2;
        k = k % nums.size();     
        int idx = nums.size() - k;
        for (int i = 0; i < idx; i++) {
            ans1.push_back(nums[i]);
        }
        for (int i = idx; i < nums.size(); i++) {
            ans2.push_back(nums[i]);
        }
        nums.clear();
        for (int i = 0; i < ans2.size(); i++) {
            nums.push_back(ans2[i]);
        }
        for (int i = 0; i < ans1.size(); i++) {
            nums.push_back(ans1[i]);
        }
    }
};