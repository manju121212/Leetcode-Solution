class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int count = 0;
       int j = 0;
       for(int i = 0;i<s.size();i++){
           if(j<g.size() && s[i]>=g[j]){
               j++;
               count++;
           }
       }
       return count;

    }
};