class Solution {
public:
    vector<int> dp;
    bool jump(int i, vector<int>& nums){

        if(i >= nums.size()-1)
            return true;

        if(dp[i] != -1)
            return dp[i];

        for(int step = 1; step <= nums[i]; step++){

            if(jump(i + step, nums))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return jump(0, nums);
    }
};