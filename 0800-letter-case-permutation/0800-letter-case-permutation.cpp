class Solution {
public:
   void solve(int index , string temp , string &s, vector<string>&res){
       if(index == s.size()){
           res.push_back(temp);
           return;
       }

       char ch = s[index];
        if(isdigit(ch)){ 
            temp.push_back(ch);
            solve(index+1,temp,s,res);
            temp.pop_back();
        }
        else{ 
            
            ch = tolower(ch);
            temp.push_back(ch);
            solve(index+1,temp,s,res);
            temp.pop_back();
            
            ch = toupper(ch);
            temp.push_back(ch);
            solve(index+1,temp,s,res);  
            temp.pop_back();
        }
       
   }
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        string temp = "";
        solve(0,temp,s,res);
        return res;
    }
};