class Solution {
public:
    int findLHS(vector<int>& nums) {
      //1 2 2 2 3 3 7
      int res = 0;
      int n = nums.size();
      sort(nums.begin(),nums.end());
       unordered_map<int,int>mpp;

       for(int i = 0;i<n;i++){
          mpp[nums[i]] = i;
       } 


       for(int i = 0;i<n;i++){
            int index = mpp[nums[i]+1];
            if(index!=0){
                  res = max(res,index-i+1);
            }
           
       }
       return res;
    }
};