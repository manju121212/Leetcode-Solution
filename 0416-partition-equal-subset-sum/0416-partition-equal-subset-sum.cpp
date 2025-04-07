class Solution {
public:
   bool solve(int index , vector<int>&nums,int target, vector<vector<int>>&dp){
       if(target == 0){
            return true;
        }

        if(target<0){
            return false;
        }

        
       
        if(index>=nums.size()){
              if(target == 0){
                return true;
              }
              return false;
        }

        if(dp[index][target] != -1){
            return dp[index][target];
        }

      
       
        bool    take = solve(index+1 , nums,target-nums[index],dp);
        

        
        bool nottake = solve(index+1 , nums,target,dp);

        return dp[index][target] = take | nottake ;
   }
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        int n = nums.size(); 
        for(int i = 0;i<n;i++){
            totalsum += nums[i];
        }

        if(totalsum % 2 != 0){
            return false;
        }

        int target = totalsum/2;
         vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return solve(0,nums,target,dp);
    }
};