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
         vector<vector<bool>>dp(n,vector<bool>(target+1,false));

        //return solve(0,nums,target,dp);
        
        for(int i = 0;i<n;i++){
            dp[i][0] = true;
        }

     

        for(int i = 1;i<n;i++){
                
                for(int j = 1;j<=target;j++){
                          bool  take = false;
                          if(j>=nums[i]){
                            take =  dp[i-1][j-nums[i]];
                          }
                         
                          bool nottake = dp[i-1][j];  

                          dp[i][j] = take |nottake;
                }
        }

        return dp[n-1][target];
    }
};