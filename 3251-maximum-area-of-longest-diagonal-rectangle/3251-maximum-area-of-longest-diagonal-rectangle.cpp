class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
       double maxDiagonal = 0;
    int maxArea = 0;
    
    for (const auto& rectangle : dimensions) {
        int length = rectangle[0];
        int width = rectangle[1];
        
       
        double diagonal = sqrt(length * length + width * width);
        int area = length * width;
        
     
        if (diagonal > maxDiagonal || (diagonal == maxDiagonal && area > maxArea)) {
            maxDiagonal = diagonal;
            maxArea = area;
        }
    }
    
    return maxArea;
    }
};