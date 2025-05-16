class Solution {
public:
   bool compare(string &g ,string &s){
       int n = g.size();
       int m = s.size();
       if(n!=m){
           return false;
       }
      int diff = 0;
       for(int i = 0;i<n;i++){
         if(g[i] != s[i]){
             diff++;
         }
       }
       if(diff ==1){
           return true;
       }
       return false;
   }

    vector<string> getWordsInLongestSubsequence( vector<string>& words, vector<int>& groups) {
        
        int maxi = 0;
        int n = words.size();
        vector<int>dp(n,1);
        vector<int>track(n);
         vector<string>ans;
        int index = 0;
        for(int i = 0 ;i<n;i++){
            track[i] = i;
        }
        
        for(int i = 1;i<n;i++){
            
            for(int prev = 0;prev<i;prev++){
                  if(compare(words[i],words[prev]) && groups[i] != groups[prev] && 1 + dp[prev] > dp[i]){
                      dp[i] = dp[prev] +1 ;
                      track[i] = prev;
                  }
            }
            if(maxi <dp[i]){
                index = i;
                maxi = dp[i];
            }
        }

        for(int i = 0 ;i<n;i++){
            cout<<dp[i]<<endl;
        }
      
       
        while(track[index] != index){

           ans.push_back(words[index]);
           index = track[index];
        }
         ans.push_back(words[index]);
       reverse(ans.begin(),ans.end());
        return ans;
    }
};