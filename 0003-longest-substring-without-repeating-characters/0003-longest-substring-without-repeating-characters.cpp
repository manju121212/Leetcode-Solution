class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> freq;
        int low = 0, res = 0;

        for (int end = 0; end < n; end++) {
            freq[s[end]]++;

            while (freq[s[end]] > 1) {
                freq[s[low]]--;
                low++;
            }

            res = max(res, end - low + 1);
        }

        return res;
    }
};
