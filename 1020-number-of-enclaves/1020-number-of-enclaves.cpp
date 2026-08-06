class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
    }
};class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    void solve(int x , int y ,  vector<vector<bool>>&vis,vector<vector<int>>& grid){
          if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || vis[x][y] == true || grid[x][y]==0){
            return;
          }

          if(grid[x][y] == 1){
                vis[x][y] = true;
                for(int i =0;i<4;i++){
                     int newx = x + dir[i][0];
                     int newy = y + dir[i][1];
                     solve(newx,newy,vis,grid);
                     
                }
          }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i = 0;i<n;i++){
             if(grid[i][0] == 1 && vis[i][0] == false){
                 solve(i,0,vis,grid);
             }
        }
           for(int i = 0;i<n;i++){
             if(grid[i][m-1] == 1 && vis[i][m-1] == false){
                 solve(i,m-1,vis,grid);
             }
        }
           for(int j = 0; j < m; j++){
    if(grid[0][j] == 1 && vis[0][j] == false){
        solve(0,j,vis,grid);
    }
}
           for(int j = 0;j<m;j++){
             if(grid[n-1][j] == 1 && vis[n-1][j] == false){
                 solve(n-1,j,vis,grid);
             }
        }

        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                  if(grid[i][j] == 1 && vis[i][j] == false){
                         count++;
                  }
            }
        }

        return count;


        

          

    }
};