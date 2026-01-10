class Solution {
public:
    
    int solve(int i , int j , string &s1 , string &s2,int n , int m, vector<vector<int>>&dp){
             if(i <0 || j<0 || i>=n || j>=m ){
                   return 0;
             }

             if(dp[i][j] != -1){
                   return dp[i][j];
             }

             if(s1[i] == s2[j]){
                   return  int(s1[i]) + solve(i-1,j-1,s1,s2,n,m,dp);
             }

             return dp[i][j] = max(solve(i-1,j,s1,s2,n,m,dp),solve(i,j-1,s1,s2,n,m,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int commDiff = solve(n-1,m-1,s1,s2,n,m,dp);
        int totalSum = 0;
        for(int i=0;i<n;i++){
               totalSum += int(s1[i]);
        }
        for(int i = 0;i<m;i++){
              totalSum += int(s2[i]);
        }

        return totalSum - 2*(commDiff);


    }
};