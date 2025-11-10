class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
         long long res = 0;
         int n = nums.size();
         for(int i = 0;i<n;i++){
             int mini = 1e9;
             int maxi = -1e9;
             for(int j = i;j<n;j++){
                 mini = min(mini , nums[j]);
                 maxi = max(maxi , nums[j]);
                 int value = maxi - mini;
                 res +=value;
             }
         }

         return res;
    }
};