class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         int n = nums.size();
       vector<long long>prefix(n,0);
       vector<long long>suffix(n,0);
       
       prefix[0] = nums[0];
       suffix[n-1] = nums[n-1];
       for(int i = 1;i<n;i++){
            if(prefix[i-1] < nums[i-1]){
                prefix[i] = nums[i-1];
            }
            else{
                prefix[i] = prefix[i-1];
            }
       }

       for(int i = n-2;i>=0;i--){
              if(suffix[i+1] < nums[i+1]){
                suffix[i] = nums[i+1];
              }
              else{
                suffix[i] = suffix[i+1];
              }
       }

       long long res = 0;
       for(int i = 1;i<n-1;i++){
             long long first = prefix[i];
             long long second = suffix[i];
             long long third = nums[i];
             
             res = max(res , (first-third)*second);

       }

       return res;
    }
};