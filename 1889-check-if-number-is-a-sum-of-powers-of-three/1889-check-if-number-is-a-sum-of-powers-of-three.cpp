class Solution {
public:
    bool checkPowersOfThree(int n) {
          int x = log(n)/log(3);
          int remain = n;
          unordered_map<int,int>mpp;
          while(remain>0){
              int value = pow(3,x);
              
              if(remain>=value){
                   remain -= value;
              }

              if(remain>=value){
                   return false;
              }
               x--;


            
              
              
          }

          return true;
    }
};