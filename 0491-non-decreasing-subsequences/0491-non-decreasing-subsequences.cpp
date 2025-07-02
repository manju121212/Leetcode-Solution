class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& temp, set<vector<int>>& res) {
        if (temp.size() >= 2) {
            res.insert(temp); // set will handle duplicates
        }
        
        for (int i = index; i < nums.size(); ++i) {
            if (temp.empty() || nums[i] >= temp.back()) {
                temp.push_back(nums[i]);
                solve(i + 1, nums, temp, res);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        solve(0, nums, temp, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
};
