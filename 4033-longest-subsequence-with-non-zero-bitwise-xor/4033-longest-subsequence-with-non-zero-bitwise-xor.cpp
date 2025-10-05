class Solution {
public:
    int solve(int i ,int curr, vector<int>&nums,vector<vector<int>>&dp){
        if(i>=nums.size()){
            if(curr >0){
                return 0;
            }
            return -1e9;
        }

        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }

     
    
       
       int take = 1 + solve(i+1,curr^nums[i],nums,dp);
        
        int nottake = solve(i+1,curr,nums,dp);

        return dp[i][curr] = max(take , nottake);
    }
    int longestSubsequence(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(1e5,-1));
        // int ans = solve(0,0,nums,dp);

        // if(ans == -1e9){
        //     return 0;
        // }
        // return ans;

          int sum = 0; 
        int count = 0;
        int prev = 0;
        for (int x : nums){
            if(x == 0){
                 count++;
            }
            sum ^= x;
        }
            
           

        int n = nums.size();

        if(count == n){
            return 0;
        }
        if (sum != 0) return n;

       
        return n - 1;
    }
};