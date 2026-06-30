class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0, c = 0;
        int n = s.size();
        int i = 0, j = 0, count = 0;
        
        while (j < n) {
            if (s[j] == 'a') a++;
            else if (s[j] == 'b') b++;
            else c++;

            while (a >= 1 && b >= 1 && c >= 1) {  
                count += (n - j); 
                if (s[i] == 'a') a--;
                else if (s[i] == 'b') b--;
                else c--;
                i++;
            }
            
            j++;
        }
        
        return count;
    }
};
