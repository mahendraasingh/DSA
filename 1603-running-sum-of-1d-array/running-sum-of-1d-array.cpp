class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int sol = 0;
        for(int i=0; i<nums.size(); i++){
            sol = sol + nums[i];
            ans.push_back(sol);
        }
        return ans;
    }
};