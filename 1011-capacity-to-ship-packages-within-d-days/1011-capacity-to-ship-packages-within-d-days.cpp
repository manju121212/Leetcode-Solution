class Solution {
public:
    bool possible(int &cap , vector<int>&weights, int &days){
           int sum = 0;
           int n = weights.size();
           int count = 0;
         int i = 0;
         while(i<n){
              if(weights[i]>cap){
                return false;
              }
              if(sum+weights[i]<=cap){
                  sum +=weights[i];
                  i++;
              }
              else{
                if(cap == 11){
                     cout<<i<<" ";
                }
                 sum = 0;
                 count++;
              }
         }
         
          
           if(count+1<=days){
               return true;
           }
           return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
          
          int low = 0;
          int high = 1e9;
          int res = -1;
       
          while(low<=high){
              int mid = low + (high-low)/2;
              if(possible(mid,weights,days)){
                   res = mid;
                  
                   high = mid-1;
              }

              else{
                  low = mid+1;
              }
               
          }

          return res; 
    }
};