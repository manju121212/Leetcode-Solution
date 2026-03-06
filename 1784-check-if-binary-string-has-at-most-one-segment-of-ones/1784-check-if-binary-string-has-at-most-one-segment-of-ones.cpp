class Solution {
public:
    bool checkOnesSegment(string s) {
         int n = s.size();
         int i = 0;
        while(i<n){
             if(s[i] == '0'){
                 break;
             }
             i++;
        }

        while(i<n){
              if(s[i] == '1'){
                  return false;
              }
              i++;
        }

        return true;
    }
};