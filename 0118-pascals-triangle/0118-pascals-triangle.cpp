class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>>ans;
         if(numRows == 1){
              ans.push_back({1});
              return ans;
         }

        
         vector<int>prev(2,1);
          ans.push_back({1});
         ans.push_back({prev});
         for(int i = 2;i<numRows;i++){
               int size = i+1;
               vector<int>curr(size,1);

               for(int j = 1;j<size-1;j++){
                    curr[j] = prev[j-1] + prev[j];
               }

               prev = curr;
               ans.push_back(curr);
         }

         return ans;
    }
};