class Solution {
public:
    int res = 0;

    void solve(int i, unordered_map<int, int>& freq, vector<int>& nums, int k) {
        if (i >= nums.size()) {
            if (!freq.empty()) res++; // count non-empty subsets
            return;
        }

        // Option 1: skip nums[i]
        solve(i + 1, freq, nums, k);

        // Option 2: include nums[i] only if valid
        if (freq[nums[i] - k] == 0 && freq[nums[i] + k] == 0) {
            freq[nums[i]]++;
            solve(i + 1, freq, nums, k);
            freq[nums[i]]--; // backtrack
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        solve(0, freq, nums, k);
        return res;
    }
};
