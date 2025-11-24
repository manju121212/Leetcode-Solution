class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
          
       map<pair<int,int>,int>mpp;
          int xor_1 = 0;
          int balance = 0;
          int res = -1;
          mpp[{0,0}] = -1;
          for(int i = 0;i<nums.size();i++){
                xor_1 = (xor_1 xor nums[i]);
                if(nums[i]%2 == 0){
                       balance--;
                }
                else{
                    balance++;
                }
                pair<int,int> p= {xor_1,balance};

                if(mpp.find(p) != mpp.end()){
                      res = max(res, i-mpp[p]);

                }
                else{
                   mpp[p] = i;
                }
               

          }
          if(res == -1){
             return 0;
          }
          return res;
    }
};