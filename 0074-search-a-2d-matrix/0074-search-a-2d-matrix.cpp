class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int leftindex =0;
        int row = matrix.size();
        int col = matrix[0].size();
        int rightindex = (row*col) -1 ;
        
        int mid = (leftindex + rightindex)/2;
        
        while(leftindex <= rightindex){
            
            int element = matrix[mid/col][mid%col];
            
            if(element == target){
                return 1;
            }
            else if(element > target){
                rightindex = mid-1;
                
            }
            else{
                leftindex = mid+1;
            }
            mid = (leftindex + rightindex)/2;
        
        }
        
        return 0;
    }
};