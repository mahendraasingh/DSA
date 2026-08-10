class Solution {
public:

    int calc(int i, vector<int>& nums, int target, int currsum) {
        if(i == nums.size()) {
            if(currsum == target)
                return 1;
            return 0;
        }
        int pos = calc(i + 1, nums, target, currsum + nums[i]);
        int neg = calc(i + 1, nums, target, currsum - nums[i]);
        return pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return calc(0, nums, target, 0);
    }
};