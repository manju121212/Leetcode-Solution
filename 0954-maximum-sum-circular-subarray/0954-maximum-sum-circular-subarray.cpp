class Solution {
public:
    int kadane_algo(vector<int>&nums){
          int n = nums.size();
          int sum = 0 ;
          int maxsum = -1e9;

          for(int i = 0;i<n;i++){

               sum +=nums[i];
               maxsum = max(maxsum,sum);
               if(sum<0){
                 sum = 0;
               }
          }

          return maxsum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int totalsum = 0;
        int Straightsum = kadane_algo(nums);
        if(Straightsum <0){
            return Straightsum;
        }
        
        for(int i = 0;i<n;i++){
            totalsum +=nums[i];
            nums[i] = -nums[i];
            
        }
        int circularsum = totalsum - (-kadane_algo(nums));

        return max(Straightsum,circularsum);
        

    }
};