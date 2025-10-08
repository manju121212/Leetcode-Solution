class Solution {
public:
    int minCut(string s) {
        int n = s.size();
         vector<vector<bool>>dp(n,vector<bool>(n,false));
         vector<vector<int>>dp2(n,vector<int>(n,-1));
        for(int g = 0;g<n;g++){

            for(int i = 0,j = g;i<n && j<n ;i++,j++){
                        
                        if(g == 0){
                             dp[i][j] = true;
                        }
                        else if(g == 1){
                              if(s[i] == s[j]){
                                   dp[i][j] = true;
                              }
                              else{
                                dp[i][j] = false;
                              }
                        }
                        else{

                            if(s[i] == s[j] && dp[i+1][j-1] == true){
                                   dp[i][j] = true;
                            }
                            else{
                                 dp[i][j] = false;
                            }
                        }
            }
        }


           
        vector<int>str(n,0);
        str[0] = 0;
   
        for(int j = 1;j<n;j++){
            if(dp[0][j] == true){
                  str[j] = 0;
            }
            else{
                 int mini = 1e9;
                 for(int i = j;i>=1;i--){
                       if(dp[i][j]){
                           mini = min(mini,str[i-1]);
                       }
                 }

                 str[j] = 1 + mini;
            }
        }

        return str[n-1];
    }
};