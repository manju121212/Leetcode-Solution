class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>>demo(n,vector<int>(m,0));
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=grid[i][0];
            if(sum<=k){
                count++;
            }
            demo[i][0] = sum;
        }
        sum = 0;
        for(int i = 0;i<m;i++){
            sum+=grid[0][i];
            if(sum<=k){
                count++;
            }
            demo[0][i] = sum;
        }
        
        sum = 0;
        
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                  int sum1 =  demo[i-1][j];
                  int sum2 = abs(demo[i][j-1] - demo[i-1][j-1]);
                  int sum3 = grid[i][j];
                
                  int finalsum = sum1 +sum2 + sum3;
                  if(finalsum <=k){
                      count++;
                  }
                  demo[i][j] = finalsum;
            }
        }
        
       
        
        count--;
        if(count<=0){
            return 0;
        }
        return count;
        
        
        
        
        
    }
};