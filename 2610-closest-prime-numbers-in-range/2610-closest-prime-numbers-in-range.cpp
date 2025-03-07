class Solution {
public:
    void check(int start , int end ,vector<bool>&isprime){
        isprime[0]=isprime[1]=false; 
        for(int i=2;i<=end;i++){
         if(isprime[i]){
           
            for(int j=2*i;j<=end;j=j+i){
                isprime[j]=false;
            }
        }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        
        int count = 0;
        int first = 0;
        int second = 0;
        int final_first = -1;
        int final_second = -1;
        int min_diff = 1e9;
        vector<int>result;
        vector<bool>isPrime(right+1,true);
        vector<int>prime_num;
        check(left , right , isPrime);
        for(int i = left;i<=right;i++){
               if(isPrime[i]){
                   prime_num.push_back(i);
               }
        }
         if (prime_num.size() < 2) {
            return {-1, -1};
        }
        for(int i = 0;i<prime_num.size();i++){
              int value = prime_num[i];
              if(isPrime[value] == true){
                  if(first == 0){
                       first = value;
                  }
                  else{
                    second = value;
                  }
                  count++;
              }

              if(count == 2){
                  
                   if(min_diff > second-first  ){
                         final_first = first;
                         final_second = second;
                         min_diff = second-first;
                   }
                   count = 1;
                   first = second;
              }
        }

        if(final_first != -1 && final_second != -1){
                 result.push_back(final_first);
                 result.push_back(final_second);
        }
        else{
                 result.push_back(-1);
                 result.push_back(-1);
        }

        return result;
    }
};