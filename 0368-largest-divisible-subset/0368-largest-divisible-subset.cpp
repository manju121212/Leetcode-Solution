class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,1);
        vector<int>parent(n);
        vector<int>res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            parent[i] = i;
          
        }
        int lastIndex = -1;
      
        int maxi = -1;
        for(int i = 0;i<n;i++){
             for(int j = i-1;j>=0;j--){
                   if(nums[i]%nums[j] == 0  && dp[j]+1 >dp[i]){
                      dp[i] = 1 + dp[j];
                      parent[i] = j;
                   }
             }

             if(maxi<dp[i]){
                   maxi = dp[i];
                   lastIndex = i;
             }
        }
        
   

    for(int i = 0;i<n;i++){
        cout<<i<<" "<<dp[i]<<" "<<parent[i]<<endl;
    }
       
       res.push_back(nums[lastIndex]);

       while(lastIndex != parent[lastIndex]){
            lastIndex = parent[lastIndex];
            res.push_back(nums[lastIndex]);
       }
       reverse(res.begin(),res.end());
        return res;

        
    }
};