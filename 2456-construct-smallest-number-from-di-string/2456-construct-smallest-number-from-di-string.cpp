class Solution {
public:
   string result = "";
    bool check(string s , string pattern){
           
           for(int i = 0;i<s.size()-1;i++){
               if(pattern[i] == 'I'){
                    if(s[i] > s[i+1]){
                        return false;
                    } 
               }
               else if(pattern[i] == 'D'){
                    if(s[i] <s[i+1]){
                        return false;
                    }
               }
           }

           return true;
    }
    void solve(string &current, vector<bool> &used, int size, int pos,string pattern) {
    if (pos == size) { 
       
        if(check(current ,pattern)){
              cout<<current<<endl;
              if(result== "" || result > current){
                   result = current;
              }
        }
        return;
    }

   
    for (char digit = '1'; digit <= '9'; digit++) {
        if (!used[digit - '1']) {  
            used[digit - '1'] = true;
            current.push_back(digit);
            solve(current, used, size, pos + 1,pattern);
            current.pop_back();
            used[digit - '1'] = false;
        }
    }
}
    string smallestNumber(string pattern) {
          string curr = "";
          int size = pattern.size()+1;
          vector<bool>used(10,false);
          solve(curr,used,size,0,pattern);
          return result;
    }
};