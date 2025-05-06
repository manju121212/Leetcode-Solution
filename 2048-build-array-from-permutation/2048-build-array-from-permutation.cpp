class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        vector<int>ans(n,0);

        while(i<n){
            ans[j++] = nums[nums[i++]];
        }

        return ans;
    }
};