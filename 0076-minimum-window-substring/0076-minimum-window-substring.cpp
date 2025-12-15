class Solution {
public:
    string minWindow(string s, string p) {
        
         map<char,int> mpp1 ,mpp2;
          int n = s.size();
          int m = p.size();
          if(n<m){
             return "";
          }
          
          for(int i=0;i<m;i++){
              mpp1[p[i]]++;
          }
          vector<int>f(2,-1);
          int count =0;
          int str_length = INT_MAX;
          for(int i=0,j=0;i<n;i++){
              char ch = s[i];
              if(mpp1.find(ch)  != mpp1.end()){
                  mpp2[s[i]]++;
                  if(mpp2[s[i]] <= mpp1[s[i]]){
                      count++;
                  }
              }
              
              while(count == m){
                  
                  if(mpp2.find(s[j]) == mpp2.end()){
                     // nothing    
                  }
                  else if(mpp2[s[j]] > mpp1[s[j]]){
                      mpp2[s[j]]--;
                  }
                  else{
                      if((i-j+1 < str_length)){
                          str_length = i-j+1;
                          f[0] = i;
                          f[1] = j;
                      }
                      mpp2[s[j]]--;
                      count--;
                      if(mpp2[s[j]]<0){
                          mpp2.erase(s[j]);
                      }
                      
                  }
                  j++;
                  
                  
              }
              
            
              
          }
          if(f[1] == -1 || f[0] == -1){
              return "";
          }
            return s.substr(f[1] ,f[0]+ 1- f[1] );
    }
};
