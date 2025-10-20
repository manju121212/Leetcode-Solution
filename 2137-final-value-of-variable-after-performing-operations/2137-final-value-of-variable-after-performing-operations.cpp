class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {

            int value = 0; 
            for(auto it : operations){
                   int n = it.size();
                   if(it[0] == '-' || it[n-1] == '-'){
                       value -=1;
                   }
                   else{
                      value++;
                   }
            }

            return value;
    }
};