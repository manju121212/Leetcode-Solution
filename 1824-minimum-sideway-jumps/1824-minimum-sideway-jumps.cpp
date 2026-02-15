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
    
    
    
    int minSideJumps(vector<int>& obstacles) {
        int n  = obstacles.size()-1;
        vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
        return solve(obstacles,2,0,n,dp );
        
        
    }
};