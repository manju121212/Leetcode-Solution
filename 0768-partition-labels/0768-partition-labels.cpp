class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int>endIndex;
        unordered_map<char,int>mpp;
        int n = s.size();
        for(int i = 0;i<n;i++){
             endIndex[s[i]] = i;
        }
        int i = 0;
        int count = 0;
        vector<int>ans;
        while(i<n){

            if(mpp.find(s[i]) == mpp.end()){
                   
                   int goTill = endIndex[s[i]];
                   while(i<=goTill ){
                        count++;
                        if(goTill<endIndex[s[i]]){
                            goTill = endIndex[s[i]];
                        }
                        mpp[s[i]]++;
                        i++;
                   }
                     ans.push_back(count);
                     count = 0;
            }      
            else{
              
              
                i++;
            }
        }

        return ans;

        
    }
}; 