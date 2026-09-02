class Solution {
public:
   string print(string s,int start,int end){
       string ans = "";
       for(int i = start;i<=end;i++){
           ans+=s[i];
       }
       return ans;
   }

    string longestPalindrome(string s) {
        

        int start = 0;
        int end = 0;
        int n = s.length();
        for(int i = 1;i<n;i++){

            int low = i-1;
            int high = i;

            while(low>=0 && high<n && s[low] == s[high] ){
                if(end <high-low+1){
                    start = low;
                    end = high-low+1;
                }
                low--;
                high++;
            }

            low = i-1;
            high = i+1;

            while(low>=0 && high<n && s[low] == s[high] ){
                if(end <high-low+1){
                    start = low;
                    end = high-low+1;
                }
                low--;
                high++;
            }

        }
        cout<<end;
        if(end ==0){
            string ans = "";
            ans.push_back(s[0]);
            return ans;
        }
        return print(s,start,end+start-1);
    }
};