class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> frwe(36, 0);

        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                frwe[ch - '0']++;
            } else {
                frwe[10 + (ch - 'a')]++;
            }
        }

        int sum = 0;

       
        for (int i = 0; i <= 4; i++) {
            sum += abs(frwe[i] - frwe[9 - i]);
        }

      
        for (int i = 0; i <= 12; i++) {
            sum += abs(frwe[10 + i] - frwe[10 + (25 - i)]);
        }

        return sum;
    }
};