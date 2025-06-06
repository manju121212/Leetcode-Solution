class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string t = "";
        string p = "";

        vector<char>minChar(n);
        minChar[n-1] = s[n-1];

        for(int i = n-2;i>=0;i--){
            minChar[i] = min(minChar[i+1],s[i]);
        }


        for(int i = 0;i<n;i++){
            t.push_back(s[i]);

            char minchar = (i+1)<n ? minChar[i+1] : s[i];

            while(!t.empty() && t.back() <= minchar){
                p += t.back();
                t.pop_back();
            }
        }

        
            while(!t.empty() ){
                p += t.back();
                t.pop_back();
            }

            return p;
    }
};