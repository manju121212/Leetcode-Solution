class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        
           int n = nums.size();
           while(true){
                bool flag = false;
                for(int i = 0;i<n;i++){
                    if(original == nums[i]){
                           original = 2*original; 
                           flag = true;
                           break;
                    }  
                }

                if(flag == false){
                      return original;
                }
           }

           return -1;
    }
};