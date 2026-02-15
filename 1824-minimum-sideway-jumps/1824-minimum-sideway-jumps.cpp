class Solution {
public:
    int solve(vector<int>& obs, int currlane,int currpos,int n, vector<vector<int>> &dp){

        if(currpos==n){
            return 0;
        }
        if(dp[currlane][currpos]!=-1){
            return dp[currlane][currpos];
        }
        
        if(obs[currpos+1] != currlane){

          return dp[currlane][currpos]=solve(obs,currlane,currpos+1,n,dp);
         
        }
        else{
         int ans = INT_MAX;    
        for(int i=1;i<=3;i++){
           
            if(obs[currpos] != i && currlane!= i){
               ans = min(ans,1+ solve(obs,i,currpos,n,dp));     
            
            }
           
        }
             dp[currlane][currpos]=ans;
             return dp[currlane][currpos];
           
        }
    }
    
    
    
    int minSideJumps(vector<int>& obs) {
        int n  = obs.size()-1;
        vector<vector<int>>dp(4,vector<int>(obs.size(),1e9));
        //return solve(obstacles,2,0,n,dp );
        
        for(int i=0;i<=3;i++){
            dp[i][n] = 0;
        }
        
        for(int currpos=n-1;currpos>=0;currpos--){
           for(int currlane = 1;currlane<=3;currlane++){
                    if(obs[currpos+1] != currlane){

                        dp[currlane][currpos]=dp[currlane][currpos+1];
         
                    }
                    else{
                       int ans = 1e9;    
                       for(int i=1;i<=3;i++){
           
                           if(obs[currpos] != i && currlane!= i){
                           ans = min(ans,1+ dp[i][currpos+1]);     
            
                          }
                        
                        }
                         dp[currlane][currpos]=ans;

                         }         
           }
        
        }
   return min(dp[2][0],min(dp[1][0]+1, dp[3][0] +1));
          
    
    
    }
};