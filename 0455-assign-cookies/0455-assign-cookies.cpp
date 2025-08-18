class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end()); 
        int j = 0;
        int n= s.size();
        int cnt = 0;
        if(s.size() == 0){
            return 0;
        }
        for(int i = 0;i<n;i++){
                if(j<g.size() && s[i]>=g[j] ){
                    cnt++;
                    j++;
                }
                
        }

        return cnt;
    }
};