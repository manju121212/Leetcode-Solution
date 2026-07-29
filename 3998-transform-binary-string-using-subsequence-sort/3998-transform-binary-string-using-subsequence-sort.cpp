class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {

    

        int one = 0;
        for (char ch : s) {
            if (ch == '1')
                one++;
        }

        vector<bool> result;

        for (string cur : strs) {

            int count1 = 0;
            int cntq = 0;

            for (char ch : cur) {
                if (ch == '1')
                    count1++;
                else if (ch == '?')
                    cntq++;
            }

            int req = one - count1;

            if (req < 0 || req > cntq) {
                result.push_back(false);
                continue;
            }

            string temp_curr = cur;

            for (int i = temp_curr.size() - 1; i >= 0; i--) {
                if (temp_curr[i] == '?') {
                    if (req > 0) {
                        temp_curr[i] = '1';
                        req--;
                    } else {
                        temp_curr[i] = '0';
                    }
                }
            }

            int a = 0;
            int b = 0;
            bool flag = true;

            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '1')
                    a++;
                if (temp_curr[i] == '1')
                    b++;

                if (b > a) {
                    flag = false;
                    break;
                }
            }

            result.push_back(flag);
        }

        return result;
    }
};