class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mini = 1e9;
        mini = min(mini,nums[k-1]-nums[0]);
        int j = 1;
        for(int i = k;i<n;i++,j++){
             mini = min(mini,nums[i]-nums[j]);
        }

        return mini == 1e9 ? 0 :mini;
       
            
    }
};