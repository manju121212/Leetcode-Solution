class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }

        string s = "11";
        
        for(int i = 3;i<=n;i++){
               string temp = "";
               
               int cons_count = 1;
               for(int j = 1;j<s.size();j++){
                      if(s[j-1] == s[j]){
                            cons_count++;
                            if(j == s.size()-1){
                                 temp += to_string(cons_count);
                                 temp+=s[j];
                            }
                      }
                      
                      else{
                       
                          temp += to_string(cons_count);
                          temp+=s[j-1];
                          cons_count = 1;
                           if(j == s.size()-1){
                                 temp += to_string(cons_count);
                                 temp+=s[j];
                            }
                      }
               }
               cout<<temp<<endl;
               s = temp;
        }

        return s;
    }
};