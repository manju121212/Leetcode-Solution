class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int start_size = 0;
        int mid_size = 0;
         int n = nums.size();

        for(int i = 0;i<n;i++){
              
              if(nums[i] < pivot){
                 start_size++;
              }
              else if(nums[i] == pivot){
                   mid_size++;
              }
        }

        int start = 0;
        int mid = start_size;
        int end = start_size + mid_size;
       
        vector<int>ans(n,0);
        for(int i = 0;i<n;i++){
             
             if(nums[i]<pivot){
                  ans[start++] = nums[i];
             }
             else if(nums[i] == pivot){
                ans[mid++] = nums[i];
             }
             else{
                ans[end++] = nums[i];
             }
        }

        return ans;
    }
};