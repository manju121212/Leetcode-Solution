class Solution {
public:
   
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n  = nums.size();
          int start = 0;
          int end = n-1;
          vector<int>ans(n,0);
          int j = 0;
          while(j<n){
               
               if(nums[j] <pivot){
                   ans[start] = nums[j];
                   start++;
               }    
               j++;   
          }
         
         
          j = 0;
          while(j<n){
             
              if(nums[j] == pivot){
                 ans[start] = nums[j];
                 start++;
              }
              
              j++;
          }
          j = 0;
          while(j<n){
            if(nums[j] >pivot){
                ans[start] = nums[j];
                start++;
              }
              j++;
          }






          return ans;
    }
};