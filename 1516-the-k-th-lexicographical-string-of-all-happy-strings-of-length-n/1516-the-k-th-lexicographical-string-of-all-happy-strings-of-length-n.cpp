class Solution {
public:
    int count = 0;
    string res = "";
    void solve(int index , char &prev , string temp , string &s,int &k , int n){
         if(temp.size() == n){
            count++;
           
            if(count == k){
              
                res = temp;
            }

            return;
         }

          for(int j = 0;j<3;j++){
               if(prev == ' ' || prev!=s[j]){
                      temp.push_back(s[j]);
                      solve(index+1,s[j],temp,s,k,n);
                      temp.pop_back();
               }
          }
    }
    string getHappyString(int n, int k) {
        string s = "abc";
        string temp = "";
        if(n == 1 && 3>=k){
             res.push_back(s[k-1]);
             return res;
        }
       
        char prev = ' ';
        solve(0,prev,temp,s,k,n);
        return res;
        
    }
};