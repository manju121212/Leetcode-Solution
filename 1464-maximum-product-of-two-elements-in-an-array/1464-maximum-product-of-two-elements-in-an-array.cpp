class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi1  = 0;
        int maxi2 = 0;
        int n = nums.size();
        for(int i = 0 ;i<n;i++){
          
          if(maxi1 <nums[i]-1){
              maxi2 = maxi1;
              maxi1 = nums[i]-1;
          }
          else if(maxi2 <nums[i]-1){
              maxi2 = nums[i]-1;
          }
           
        }

        return maxi1 *maxi2;
       

    
    }
};