class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int prev = 1e9;
        int ans = -1;
        for(int i = 0;i<capacity.size();i++){
              if(prev > capacity[i] && capacity[i] >=itemSize){
                   prev= capacity[i];
                   ans = i;
              }
             
        }

        return ans;
    }
};