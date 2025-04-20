class Solution {
public:
    static vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        int n = nums.size();
        vector<vector<long long>> dp;

        // Iterate for each possible remainder (req) from 0 to k-1
        for (int req = 0; req < k; req++) {
            dp = vector<vector<long long>>(n, vector<long long>(k + 1, -1));
            ans[req] = solve(0, req, -1, k, nums, dp);
        }

        return ans;
    }

    static long long solve(int i, int req, int pro, int k, vector<int>& arr, vector<vector<long long>>& dp) {
        // Base case: If we've processed all elements in the array
        if (i == arr.size()) return 0;
        
        // If this state has already been computed, return the cached result
        if (dp[i][pro + 1] != -1) return dp[i][pro + 1];

        long long take = 0, notTake = 0, count = 0;

        // If the product is -1 (starting a new subarray)
        if (pro == -1) {
            int currMod = arr[i] % k;
            if (currMod == req) count = 1;

            take = count + solve(i + 1, req, currMod, k, arr, dp);
            notTake = solve(i + 1, req, -1, k, arr, dp);
        } else {
            // Otherwise, continue multiplying the elements
            int newPro = ((pro % k) * (arr[i] % k)) % k;
            if (newPro == req) count = 1;

            take = count + solve(i + 1, req, newPro, k, arr, dp);
        }

        // Cache the result before returning
        return dp[i][pro + 1] = take + notTake;
    }
};