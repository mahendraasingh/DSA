class Solution {
public:

    void solve(int index, vector<int>& nums, vector<int>& curr,
               vector<vector<int>>& ans) {
        if (curr.size() >= 2) {
            ans.push_back(curr);
        }
        unordered_set<int> used;
        for (int i = index; i < nums.size(); i++) {
            if (!curr.empty() && nums[i] < curr.back()) {
                continue;
            }
            if (used.count(nums[i])) {
                continue;
            }
            used.insert(nums[i]);
            curr.push_back(nums[i]);
            solve(i + 1, nums, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, nums, curr, ans);
        return ans;
    }
};