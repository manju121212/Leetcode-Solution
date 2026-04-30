class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int,int> mpp;
        mpp[0] = 0;
        mpp[1] = 1;
        mpp[2] = 1;

       
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));

      
        int startCost = mpp[grid[0][0]];
        if(startCost > k) return -1;
        dp[0][0][startCost] = grid[0][0];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int cost = 0; cost <= k; cost++){
                    if(dp[i][j][cost] == -1) continue;

                    int currScore = dp[i][j][cost];

                  
                    if(j+1 < m){
                        int v = mpp[grid[i][j+1]];
                        if(cost + v <= k){
                            dp[i][j+1][cost + v] = max(dp[i][j+1][cost + v], currScore + grid[i][j+1]);
                        }
                    }

                  
                    if(i+1 < n){
                        int v = mpp[grid[i+1][j]];
                        if(cost + v <= k){
                            dp[i+1][j][cost + v] = max(dp[i+1][j][cost + v], currScore + grid[i+1][j]);
                        }
                    }
                }
            }
        }

       
        int ans = -1;
        for(int cost = 0; cost <= k; cost++){
            ans = max(ans, dp[n-1][m-1][cost]);
        }

        return ans;
    }
};
