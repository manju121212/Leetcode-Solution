class Solution {
public:
    int arrangeCoins(int n) {
        int counter = 0;
        int res = 0;
        while(n>=0){
             counter++;
             int value = n - counter;
             if(value>=0){
                res++;
             }
             n = value;

        }
        return res;
    }
};