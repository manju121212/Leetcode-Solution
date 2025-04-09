class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
         set<int>st;
         for(auto it : nums){
               if(it>k){
                   st.insert(it);
               }
               else if(k == it){
                 continue;
               }
               else{
                return -1;
               }
         }

         return st.size();
    }
};