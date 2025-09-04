class Solution {
public:
    int findClosest(int x, int y, int z) {
        int first_person = abs(x-z);
        int second_person = abs(y-z);
        
        if(first_person<second_person){
              return 1;
        }
        else if(first_person>second_person){
            return 2;
            
            
        }
        else{
            return 0;
        }
        
        
        
    }
};