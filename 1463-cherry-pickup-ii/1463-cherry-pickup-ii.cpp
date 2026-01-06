class Solution {
public:

int solve(int i , int j1 , int j2,int r , int c ,vector<vector<int>>&grid,   vector<vector<vector<int>>>&dp){
       if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c){
                 return -1e9;
       }
           
          if(i == r-1){
               
               int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
               return value;
          }

          if(dp[i][j1][j2] != -1){
                return dp[i][j1][j2];
          }

        int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        int maxi = -1e9;
        for(int alice = -1;alice<=1;alice++){
             for(int bob = -1;bob<=1;bob++){
                   maxi = max(maxi , value + solve(i+1,j1+alice,j2+bob,r,c,grid,dp));

             }
        }

        return dp[i][j1][j2] = maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r,
      vector<vector<int>>(c, vector<int>(c, -1)));
 
    return solve(0,0,c-1,r,c,grid,dp);
    }
};