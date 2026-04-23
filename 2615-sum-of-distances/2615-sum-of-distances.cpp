class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for (auto &it : mp) {
            vector<int>& pos = it.second;
            int m = pos.size();

           
            vector<long long> prefix(m + 1, 0);
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + pos[i];
            }

            for (int k = 0; k < m; k++) {
                long long left = (long long)pos[k] * k - prefix[k];
                long long right = (prefix[m] - prefix[k + 1]) - 
                                  (long long)pos[k] * (m - k - 1);

                ans[pos[k]] = left + right;
            }
        }

        return ans;
    }
};