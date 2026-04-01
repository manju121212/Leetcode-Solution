class Solution {
public:
    int firstMatchingIndex(string s) {

        int i = 0;
        int n = s.size();
        int j = n-1;

        while(i<=j){
            if(s[i] == s[j]){
                 return i;
            }
            i++;
            j--;
        }

        return -1;
    }
};