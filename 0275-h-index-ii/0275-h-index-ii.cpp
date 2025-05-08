class Solution {
public:
   bool check(int threshold ,vector<int>& citations ){
          int count = 0;
          for(int i = 0;i<citations.size();i++){
               
                if(citations[i]>=threshold){
                    count++;
                }
          }

          if(count >=threshold){
            return true;
          }
          return false;
   }
    int hIndex(vector<int>& citations) {
        
        int low = 0;
        int high = *max_element(citations.begin(),citations.end());
        int res = -1;
     
        while(low<=high){
            int mid = low + (high - low)/2;
            if(check(mid , citations)){
                  res = mid;
                  low = mid+1;
            }
            else{
                 high = mid-1;
            }
        }

        return res;
    }
};