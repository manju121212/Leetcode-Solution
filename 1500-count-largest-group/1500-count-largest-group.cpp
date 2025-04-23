class Solution {
public:
    int countLargestGroup(int n) {
           int digit = 1;
          
           unordered_map<int,int>mpp;
           while(digit<=n){
              string s = to_string(digit);
                int value = 0;
                for(int i = 0;i<s.size();i++){
                            value += s[i] - '0';
                          

                } 
                mpp[value]++;
                digit++;
           }

           int count = 0;
           int maxi = -1;
           for(auto it : mpp){
               cout<<it.first<<" "<<it.second<<endl;
               if(maxi < it.second){
                  maxi = it.second;
                 
               }
              
           }



           for(auto it : mpp){

              if(maxi == it.second){
                   count++;
              }



           }

           return count;
    }
};