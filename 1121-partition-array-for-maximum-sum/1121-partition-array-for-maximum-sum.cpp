class Solution {
public:
int solve(int i , vector<int>&arr, int n , int k,vector<int>&dp){
        if(i >=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxSum = -1;
        int maxi = -1;
        for(int j = i;j<min(i+k,n);j++){
            int len = j-i+1;
            maxi = max(maxi ,arr[j]);
            
            int sum = (len*maxi) + solve(j+1,arr,n,k,dp);
            maxSum = max(maxSum,sum);
        }
        return dp[i] = maxSum ;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
          int n = arr.size();
          vector<int>dp(n,-1);
           return solve(0,arr,n,k,dp);
    }
};