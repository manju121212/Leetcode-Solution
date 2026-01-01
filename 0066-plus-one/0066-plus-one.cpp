class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
            // 1 8 9
            // 1 9 9
            // 9 8 1
            // 0 9 1
            int value = 0;
            int carry = 0;

          int n = digits.size();
          vector<int>res;
           for(int i = n-1;i>=0;i--){
                  
                 if(i == n-1){
                      value = digits[i]+1;
                      int digit = value%10;
                      carry = value/10;
                      res.push_back(digit);
                 }
                 else{
                      value = digits[i] + carry;
                      int digit = value%10;
                      carry = value/10;
                      res.push_back(digit);
                 }

           }
           cout<<carry<<endl;
           if(carry != 0){
                
                res.push_back(carry);
           }
           reverse(res.begin(),res.end());
           return res;


    }
};