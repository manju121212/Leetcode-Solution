class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string,int>mpp;
        int n = dominoes.size();
        for(int i = 0;i<n;i++){
             int first = dominoes[i][0];
             int second = dominoes[i][1];
             string temp = "";
             if(second>first){
                  temp += to_string(first);
                  temp += to_string(second);
                  mpp[temp]++;
             }
             else if(first>second){
                  temp += to_string(second);
                  temp += to_string(first);
                  mpp[temp]++;
             }
             else{
                  temp += to_string(first);
                  temp += to_string(second);
                  mpp[temp]++;
             }
        }
        
        int total_pairs = 0;
        for(auto it : mpp){
            int pairs = (it.second*(it.second-1))/2;
            total_pairs += pairs;
        }

        return total_pairs;
    }
};