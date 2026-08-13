class Solution {
public:

    const int MOD = 1e9 + 7;
    int solve(int dice, int target, int k, vector<vector<int>>& dp) {
        if (dice == 0) {
            if (target == 0)
                return 1;
            else
                return 0;
        }
        if (target < 0)
            return 0;
        if (dp[dice][target] != -1)
            return dp[dice][target];

        long long ways = 0;
        for (int face = 1; face <= k; face++) {
            ways += solve(dice - 1,
                          target - face,
                          k,
                          dp);

            ways %= MOD;
        }
        return dp[dice][target] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1,
                               vector<int>(target + 1, -1));

        return solve(n, target, k, dp);
    }
};