class Solution {
public:
    int maxProduct(int n) {
        
        string s = to_string(n);
        
        sort(s.begin(),s.end());
        int m = s.size();
        int first = s[m-2] - '0';
        int second = s[m-1] - '0';
        return first*second;
    }
};