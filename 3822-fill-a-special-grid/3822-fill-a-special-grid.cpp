class Solution {
public:
   int value = 0;
   void solve(int row , int col , int size ,vector<vector<int>>&grid ){
        
        if(size == 1){
            grid[row][col] = value;
            value++;
            return ;
        }

        int subsize = size/2;

        solve(row,col+subsize,subsize,grid);
        solve(row+subsize,col+subsize,subsize,grid);
        solve(row+subsize,col,subsize,grid);
        solve(row , col , subsize,grid);

   }
    vector<vector<int>> specialGrid(int n) {
        int size = 1<<n;
        vector<vector<int>>grid(size , vector<int>(size,0));
         solve(0,0,size,grid);

         return grid;
    }
};