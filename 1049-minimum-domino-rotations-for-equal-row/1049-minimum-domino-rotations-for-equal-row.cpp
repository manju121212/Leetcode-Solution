class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>mpp;
        int n = tops.size();
        int targeted_value = -1;
        for(int i = 0;i<n;i++){
               if(tops[i] == bottoms[i]){
                mpp[tops[i]]++;
               }
               else{
                   mpp[tops[i]]++;
                   mpp[bottoms[i]]++;
               }
        }

        for(auto it : mpp){
            if(it.second == n){
                targeted_value = it.first;
                break;
            }
        }

        if(targeted_value == -1){
            return -1;
        }
        int swaps_1 = 0;
        int swaps_2 = 0;
        for(int i = 0;i<n;i++){
              if(tops[i] != targeted_value){
                swaps_1++;
              }
              if(bottoms[i] != targeted_value){
                swaps_2++;
              }
        }


        return min(swaps_1,swaps_2);
    }
};