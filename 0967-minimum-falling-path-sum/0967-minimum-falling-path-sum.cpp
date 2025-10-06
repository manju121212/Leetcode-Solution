class Solution {
public:
    int solve(int i , int j ,vector<vector<int>>& matrix,int n ,int m,vector<vector<int>>&dp ){
        if(i>=n || j>=m ||i<0 || j<0){
              return 1e9;
        }
           if(i == n-1 ){
                return matrix[i][j];
           }

           if(dp[i][j] != -1){
                return dp[i][j];
           }

           int diag_left = matrix[i][j] + solve(i+1,j-1,matrix,n,m,dp);
           int diag_right = matrix[i][j] + solve(i+1,j+1,matrix,n,m,dp);
           int down=  matrix[i][j] + solve(i+1,j,matrix,n,m,dp);

           return dp[i][j] = min({diag_left,diag_right,down});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
          int n = matrix.size();
          int m = matrix[0].size();
            vector<vector<int>>dp(n,vector<int>(m,-1));
        //   int mini = 1e9;
         
        //     for(int j = 0;j<m;j++){
                  
        //             mini  = min(mini,solve(0,j,matrix,n,m,dp));
        //     }
          
        //   return mini;

         
        for(int j = 0;j<m;j++){
            dp[n-1][j] = matrix[n-1][j];
        }
          

          for(int i = n-2;i>=0;i--){
                  
                  for(int j = m-1;j>=0;j--){
                        int diag_left = 1e9,diag_right = 1e9,down = 1e9;

                        if(i+1<n && j-1>=0){
                             diag_left = matrix[i][j] + dp[i+1][j-1];
                        }
                        if(i+1<n && j+1<m){
                            diag_right = matrix[i][j] + dp[i+1][j+1];
                        }
                        if(i+1<n){
                              down = matrix[i][j] + dp[i+1][j];
                        }

                        dp[i][j] = min({diag_left,diag_right,down});

                  }
          }

          int mini = 1e9;

          for(int j = 0;j<m;j++){
               mini = min(mini,dp[0][j]);
          }
          return mini;

          
    }
};