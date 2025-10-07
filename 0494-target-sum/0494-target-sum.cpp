class Solution {
public:
    int solve(int index ,vector<int>& nums, int target){
           
           if(index>=nums.size()){
               if(target == 0){
                    return 1;
               }
               return 0;
           }

           
           int pos = solve(index+1,nums,target-nums[index]);
           int neg = solve(index+1,nums,target - (-nums[index]));

           return pos + neg;
           
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        

        return solve(0,nums,target);
    }
};