class Solution {
public:
   int find_removal(string s){

       stack<char>st;
       for(int i=0;i<s.size();i++){
           char ch = s[i];
           if(ch == '('){
               st.push(ch);
           }
           else if (ch==')'){
               if(!st.empty() && st.top() == '('){
                   st.pop();
               }
               else{
                   st.push(ch);
               }
           
           }
       }
       return st.size();
   }
  void solve(string s ,int removal,vector<string>&ans,int n,  unordered_map<string ,bool>&mpp){
      if(mpp[s]== true){
           return ;
      }
      mpp[s] = true;
      if(removal ==0){
          int remove = find_removal(s);
          if(remove==0){
              ans.push_back(s);
          }
          return ;
      }
      for(int i=0;i<s.length();i++){
          string leftpart = s.substr(0,i);
          string rightpart = s.substr(i+1);
          string totalstring = leftpart + rightpart ;
          solve(totalstring ,removal-1,ans,n,mpp);
      }
      return ;
  }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        int remove = find_removal(s);
        int n = s.size();
        unordered_map<string ,bool>mpp;
        solve(s,remove,ans,n,mpp);
        return ans;
    }
};