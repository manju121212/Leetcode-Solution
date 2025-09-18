class Solution {
    
    private:
    void solve(int col,vector<vector<string>>&ans, vector<string>&board,  vector<int>&leftrow, vector<int>&updiagonal, vector<int>&lowdiagonal,int n){
        
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && updiagonal[n-1+col-row]==0 && lowdiagonal[row+col]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                updiagonal[(n-1)+col-row]=1;
                lowdiagonal[row+col]=1;
                solve(col+1,ans,board,leftrow,updiagonal,lowdiagonal,n);
                board[row][col]='.';
                leftrow[row]=0;
                updiagonal[(n-1)+col-row]=0;
                lowdiagonal[row+col]=0;
            }
        }
        
        
        
        
        
        
        
        
        
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftrow(n,0);
        vector<int>updiagonal(2*n-1,0);
        vector<int>lowdiagonal(2*n-1,0);
        solve(0,ans,board,leftrow,updiagonal,lowdiagonal,n);
        return ans;
        
    }
};