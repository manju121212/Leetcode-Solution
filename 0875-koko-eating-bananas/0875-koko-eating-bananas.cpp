class Solution {
public:
   bool isPossible(long long point , vector<int>&piles,int h){
       long long count = 0;

       for(int i = 0;i<piles.size();i++){
           if((piles[i]%point) == 0){
              count  += (piles[i]/point);
           }
           else{
               count += (piles[i]/point) + 1;
           }
       }

       if(count<=h){
           return true;
       }
       return false;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
          
          int res = 0;
         
          int low = 1;
          int high = *max_element(piles.begin(),piles.end());

          while(low<=high){
              long long mid = low + (high - low)/2;

              if(isPossible(mid,piles,h)){
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