class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
          int res = 0;
          int n = points.size();
          for(int i = 0;i<n-1;i++){
               
               int x1 = points[i][0];
               int y1 = points[i][1];
               
               int x2 = -1;
               int y2 = -1;
               

               if(i+1<n){
                   x2 = points[i+1][0];
                   y2 = points[i+1][1];
               }

               res += max(abs(x2-x1) , abs(y2-y1));
          }

          return res;
    }
};