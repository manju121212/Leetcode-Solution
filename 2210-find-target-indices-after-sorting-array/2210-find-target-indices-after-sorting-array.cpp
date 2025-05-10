class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        vector<int>res;
        int  left = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int right = upper_bound(nums.begin(),nums.end(),target) - nums.begin();

        for(int i = left ;i<right;i++){
            res.push_back(i);
        }
        return res;

        

    }
};