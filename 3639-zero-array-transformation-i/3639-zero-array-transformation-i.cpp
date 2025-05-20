class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         int n = nums.size();
         vector<int>prefix(n+1,0);
          vector<int>dp;
         for(auto it : queries){
               int start = it[0];
               int end = it[1];
               prefix[start] +=1;
               prefix[end+1] -=1;
         }

         int curr_oper = 0;
         for(int it : prefix){
              curr_oper += it;
              dp.push_back(curr_oper);
         }

         for(int i = 0;i<n;i++){
            if(dp[i]<nums[i]){
                return false;
            }
         }
         return true;   

    }
};