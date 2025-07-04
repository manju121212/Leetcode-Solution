class Solution {
public:
    void solve(int index , string temp,unordered_map<int,string>&mpp,string &digits,vector<string>&res){
         
         if(index>=digits.size()){
                if(temp.size()!=0){
                  res.push_back(temp);
                }
                return;
         }

         int new_index = digits[index] - '0';
         string value = mpp[new_index];

         for(int i = 0;i<value.size();i++){
               temp.push_back(value[i]);
               solve(index+1,temp,mpp,digits,res);
               temp.pop_back();

         }

    }
    vector<string> letterCombinations(string digits) {
        string temp = "";
        vector<string>res;
        unordered_map<int,string>mpp;
        mpp[2] = "abc"; 
         mpp[3] = "def"; 
          mpp[4] = "ghi"; 
           mpp[5] = "jkl"; 
            mpp[6] = "mno"; 
             mpp[7] = "pqrs"; 
              mpp[8] = "tuv"; 
               mpp[9] = "wxyz"; 
        solve(0,temp,mpp,digits,res);
        return res;
    }
};