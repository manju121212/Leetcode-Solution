class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        
        
        int row = grid.size();
        int col = grid[0].size();
        int high = row*row;
        unordered_map<int,int>mpp;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
               mpp[grid[i][j]]++;
            }
        }
        int a = 0;
        int b = 0;
        for(int i = 1;i<=high;i++){
            if(mpp[i]==2){
                a = i;
            }
            
            if(mpp[i]==0){
                b = i;
                cout<<b;
            }
        }
        vector<int>ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
        
        
        
        
    }
};