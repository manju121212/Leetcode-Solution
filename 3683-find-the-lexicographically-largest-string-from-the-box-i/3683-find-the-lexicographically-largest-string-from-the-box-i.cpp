class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1){
            return word;
                    }
        int longSize = n - (numFriends-1);
        string res = "";
        for(int i = 0;i<n;i++){
              int possSize = min(longSize, n-i);

              res = max(res,word.substr(i,possSize));
        }
        return res;
    }
};