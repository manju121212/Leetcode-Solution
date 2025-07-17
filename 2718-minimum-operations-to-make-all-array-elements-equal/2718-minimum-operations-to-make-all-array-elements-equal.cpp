class Solution {
public:
    long long bs(vector<int>& nums, vector<long long>& prefix, int ele) {
        int low = 0, high = nums.size() - 1;
        int n = nums.size();
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= ele) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        long long firsthalf = 0, secondhalf = 0;

        if (res >= 0) {
            firsthalf = 1LL * ele * (res + 1) - prefix[res];
        }

        if (res < n - 1) {
            secondhalf = prefix[n - 1] - (res >= 0 ? prefix[res] : 0LL) - 1LL * ele * (n - (res + 1));
        }

        return firsthalf + secondhalf;
    }

    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n, 0);  // Use long long

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];  // Now safe from overflow
        }

        vector<long long> ans;
        for (int ele : queries) {
            ans.push_back(bs(nums, prefix, ele));
        }

        return ans;
    }
};
