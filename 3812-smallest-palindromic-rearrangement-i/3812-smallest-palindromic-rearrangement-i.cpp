class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        sort(s.begin(),s.end());
        string res(s.size(),'#');

       int i = 0;
       int j = 0;
       int k = n-1;

       while(i<n){
           if(i+1<n && s[i] ==s[i+1]){
                 res[j++] = s[i];
                 res[k--] = s[i];
                 i+=2;
           }
           else{
                int mid = n/2;
                res[mid] = s[i];
                i++;
           }
       }

       return res;
    }
};