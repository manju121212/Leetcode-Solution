class Solution {
public:
    int maxOperations(string s) {
        
        int n = s.size();
        int count = 0;
        int res = 0;
        for(int i = 0;i<n;i++){
              
              if(s[i] == '1'){
                 count++;
              }
              else{
                  while(i<n && s[i] == '0'){
                       i++;
                       
                  }
                  if(i<n){
                    i--;
                  }
                  res +=count;
              }
        }

        return res;
    }
};