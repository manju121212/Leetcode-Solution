class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int i = 0;
        vector<string>res;
        string temp = "";
        while(i<n){
           temp = "";
           int count = 0;

           while(i<n && count<k){
                temp +=s[i];
                count++;
                i++;
           }
           if(count == k){
               res.push_back(temp);

           }
           else{
               break;
           }

        }
        
        if(temp.size()!=k){
            while(temp.size()!=k){
                temp += fill;
            }
            res.push_back(temp);
            return res;
        }
        else{
            return res;
        }
           


    }
};