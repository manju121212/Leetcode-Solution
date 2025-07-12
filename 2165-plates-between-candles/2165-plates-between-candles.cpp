class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candles_pos;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '|') {
                candles_pos.push_back(i);
            }
        }

       
        vector<int> prefix(candles_pos.size(), 0);
        for (int i = 1; i < candles_pos.size(); i++) {
            int plates_between = candles_pos[i] - candles_pos[i - 1] - 1;
            prefix[i] = prefix[i - 1] + plates_between;
        }

        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

          
            int index1 = lower_bound(candles_pos.begin(), candles_pos.end(), u) - candles_pos.begin();
           
            int index2 = upper_bound(candles_pos.begin(), candles_pos.end(), v) - candles_pos.begin()-1 ;

            int final_ans = 0;
            if (index1 < candles_pos.size() && index2<candles_pos.size() && index1<index2) {
                final_ans = prefix[index2] - prefix[index1];
            }

            res.push_back(final_ans);
        }

        return res;
    }
};
