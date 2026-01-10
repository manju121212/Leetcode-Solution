class Solution {
public:
    int dp[501][501];
   int solve(int i ,int j,vector<int>& nums1, vector<int>& nums2,int n,int m ){
       if(i==n || j==m){
            return -1e9;
       }
       if(dp[i][j] != -1){
           return dp[i][j];
       }
       int value = nums1[i]*nums2[j];
       int take_single = value;
       int take_both = value + solve(i+1,j+1,nums1,nums2,n,m);
       int take_i = solve(i,j+1,nums1,nums2,n,m);
       int take_j = solve(i+1,j,nums1,nums2,n,m);

       return dp[i][j] = max({take_single,take_both,take_i,take_j});

   }


    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
          for(int i = 0; i<501; i++) {
            for(int j = 0; j < 501; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(0,0,nums1,nums2,n,m);
    }
};