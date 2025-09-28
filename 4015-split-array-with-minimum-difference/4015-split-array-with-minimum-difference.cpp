class Solution {
public:
    long long splitArray(vector<int>& nums) {
          
          int n = nums.size();
          long long res = LLONG_MAX;
          vector<bool>left_poss(n,false);
          vector<bool>right_poss(n,false);
          vector<long long>prefix(n,0);
          prefix[0] = nums[0];
         
          for(int i = 1;i<n;i++){
              prefix[i] = prefix[i-1] + nums[i];
          }
          
          left_poss[0] = true;
          for(int i = 1;i<n;i++){
              left_poss[i] = left_poss[i-1] && (nums[i]>nums[i-1]);
          }
          
          right_poss[n-1] = true;
          for(int i = n-2;i>=0;i--){
              right_poss[i]  = right_poss[i+1] && (nums[i]>nums[i+1]);
          }
          bool flag = false;
          for(int i = 0;i<n-1;i++){
               if(left_poss[i] && right_poss[i+1]){
                      long long left_part = prefix[i];
                      long long right_part = prefix[n-1] - prefix[i];

                      res = min(res,llabs(left_part - right_part));
                      flag = true;
               }
          }

          return flag ? res : -1;
  
         
    }
};