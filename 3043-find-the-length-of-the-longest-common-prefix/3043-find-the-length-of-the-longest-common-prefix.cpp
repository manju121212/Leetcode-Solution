class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<int ,int>mpp;

        for(auto it : arr2){
            int val =it;
            while(mpp[val]<=0 && val!=0){
                   mpp[val] = 1;
                   val = val/10;

            }
        }
        int longestprefix = 0;
        for(auto it : arr1){
            int val = it ;
            int count = 0;
            while(val!=0){
                if(mpp[val] ==1){
                    count++;
                  
                    
                }
                val = val/10;
            }

            longestprefix = max(longestprefix,count);
        }

        return longestprefix;
    }
};