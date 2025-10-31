class Solution {
public:
    int solve(int index,vector<int>&nums){
        if(index == nums.size()-1){
              return 0;
        }
        if(index>=nums.size()){
              return 1e9;
        }
        

        int mini = 1e9;
        for(int j = 1;j<=nums[index];j++){
            int v = solve(j+index,nums);
            if(v!=1e9){
                 mini = min(mini,1+v);
            }
        }

        return mini;
    }
    int jump(vector<int>& nums) {
         
         return solve(0,nums);
    }
};