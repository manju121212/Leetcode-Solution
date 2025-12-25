class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.rbegin(),happiness.rend());
      


        int dec = 0;
        long long total = 0;
        for(int i = 0;i<happiness.size();i++){
                if(k >0){
                    long long value = happiness[i] - dec;
                    if(value>=0){
                          total += value;
                    }
                    dec++;
                    
                }
                else{
                     break;
                }
                k--;

                 

        }

        return total;
    }
};