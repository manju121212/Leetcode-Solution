class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int  n = nums.size();
        if(n == 1){
            return true;
        }
        for(int i = 0;i<n-1;i++){
            int maxdistance = max(maxdistance , i + nums[i]);

            if(maxdistance == i){
                  return false;
            }
        }

        return true;
    }
};
