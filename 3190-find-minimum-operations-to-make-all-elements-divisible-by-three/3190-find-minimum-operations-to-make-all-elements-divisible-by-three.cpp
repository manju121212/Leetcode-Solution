class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int count = 0;
         for(auto it : nums){
              if(it%3 !=0){
                   count++;
              }
         }

         return count;
    }
};