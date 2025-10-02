class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int empty = numBottles;
        int full = 0;
        int exch = numExchange;
        int drunk = numBottles;
        int prev = -1;
        while(true){
             
             if(empty >= exch){
                 empty = empty - exch ;
                 prev = empty;
                 exch++;
                 full++;
             }
             else if(empty<exch){
                  drunk += full;
                  empty = full + empty;
                  full = 0;
                  if(empty == prev){
                    break;
                  }
                  prev = empty;
             }
            
        }

        return drunk;
    }
};