class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int count = 0;
        unordered_map<char,int> mpp;

        while(r < n) {
            mpp[s[r]]++;

            while(mpp.size() >= 3) {
              
                count += (n - r);

               
                if(mpp[s[l]] == 1) {
                    mpp.erase(s[l]);
                } else {
                    mpp[s[l]]--;
                }
                l++;
            }
            r++;
        }

        return count;
    }
};
