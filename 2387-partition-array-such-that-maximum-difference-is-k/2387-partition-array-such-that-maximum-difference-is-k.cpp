class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count = 0;
        int i = 0;
        while(i<n){
            int maxi = nums[i];
            int mini = nums[i];
            
            while(i<n && (maxi-mini)<=k){
                i++;
                if(i<n){
                   maxi = max(maxi , nums[i]);
                   mini = min(mini,nums[i]);
                }
                
            }
            
            count++;
        }

        return count;
    }
};