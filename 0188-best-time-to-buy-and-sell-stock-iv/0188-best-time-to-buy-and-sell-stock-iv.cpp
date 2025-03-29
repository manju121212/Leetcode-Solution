class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        
        int n= arr.size();
        vector<vector<int>>dp(k+1,vector<int>(n));
        
        for(int t=1;t<=k;t++){
            for(int d=1;d<n;d++){
                
                // take previous day transaction  profit 
                int max = dp[t][d-1];
                
                for(int pd= 0;pd< d;pd++){
                    
                    int a= dp[t-1][pd];
                    int b= arr[d]- arr[pd];
                    
                    if(a + b > max){
                       max= a+b;
                    }
                }
                
                dp[t][d] =max;
                
                
            }
            
        }
        
        return dp[k][n-1];
        
    }
};