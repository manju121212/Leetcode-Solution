class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n= prices.size();  
     int pst= 0;
     int lbp= prices[0];
     
     vector<int>dp1(n);
     dp1[0]= 0;   
     for(int i=1 ;i<n;i++){
        
         // identify least buying point till date
         if(prices[i] < lbp){
             lbp= prices[i];
         }
         
         // calculate profit on present day
         int pst = prices[i] - lbp;
         
         // calculate maxprofit till date 
         if(pst < dp1[i-1]){
             dp1[i]= dp1[i-1];
         }
         else{
             dp1[i] =pst;
         }    
     }
        
        
     int pbt=0;
     int mst= prices[n-1];  
     vector<int>dp2(n);
    
    dp2[n-1]= 0;
      
     for(int i=n-2;i>=0;i--){
         
         // calculate max selling point
         if(prices[i] > mst){
             mst= prices[i];
         }
         
          pbt= mst- prices[i];
          
          if(pbt > dp2[i+1]){
              dp2[i]= pbt;
          }
          else{
              dp2[i] = dp2[i+1];
          }   
     }
     int finalmax=0;
     
        for(int i=0;i<n;i++){
            int ans=  dp1[i] + dp2[i];
            finalmax= max(finalmax,ans);
        }
        
        return finalmax;
        
    }
};
