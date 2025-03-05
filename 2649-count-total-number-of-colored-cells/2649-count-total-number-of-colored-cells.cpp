class Solution {
public:
    long long coloredCells(int n) {
        long long res = 1;
        long long temp = 1;
        if(n == 1){
            return 1;
        }
         for(int i = 1;i<n;i++){
             
              res = res + (4*i);
             
             
         }

         return res;
    }
};