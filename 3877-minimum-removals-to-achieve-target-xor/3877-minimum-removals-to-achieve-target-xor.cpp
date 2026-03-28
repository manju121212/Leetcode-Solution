class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
           unordered_map<int, int> dp;
            dp[0] = 0;

        for (int num : nums) {
            auto curr_dp = dp;
            for (auto &[x, size] : dp) {
                int currXor = x ^ num;
                curr_dp[currXor] = max(curr_dp[currXor], size + 1);
            }
            dp = curr_dp;
        }

        if (dp.find(target) == dp.end()) return -1;

        return nums.size() - dp[target];
    }
};