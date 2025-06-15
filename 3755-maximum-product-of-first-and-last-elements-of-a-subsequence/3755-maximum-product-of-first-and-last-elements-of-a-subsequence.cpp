class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
         
         long long res = LLONG_MIN;
         set<int>st;
         if(m == 1){
              for(auto x : nums){
                  res = max(res,(long long)x*x);
              }
              return res;
         }
         int n = nums.size();
         for(int i = m-1;i<n;i++){
               st.insert(nums[i-(m-1)]);

               int mini = *(st.begin());
               int maxi = *(st.rbegin());
               
               res = max(res,(long long)nums[i]*mini);
               res = max(res,(long long)nums[i]*maxi);
         }
         return res;
    }
};