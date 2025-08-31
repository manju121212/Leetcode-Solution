class Solution {
    public int maxCoins(int[] nums) {
        int [][]dp = new int[nums.length][nums.length];
        
          for(int g=0;g<nums.length;g++){
            for(int i=0,j=g;j<nums.length;i++,j++){
                
              int maxi= Integer.MIN_VALUE;
                
              for (int k=i;k<=j;k++){
                   int left= k==i? 0 : dp[i][k-1];
                   int right = k==j? 0:dp[k+1][j];
                  
                   int val = nums[k];
                   
                   if(i>0){   // it should not stand on 0 position 
                       val *= nums[i-1];
                   }
                   if(j <nums.length-1){
                     val *= nums[j+1];
                   }
                  int total = val + left+right;
                  
                  if(total > maxi){
                      maxi =total;
                  }
              
              }
                dp[i][j]= maxi;
                
            }
        
        }
        return dp[0][nums.length-1];
    }
}