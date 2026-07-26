class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& a,
                                            vector<vector<int>>& b) {

    

        int i = 0, j = 0;
        vector<vector<int>> ans;

        while (i < a.size() || j < b.size()) {

            if (j == b.size() || (i < a.size() && a[i][0] < b[j][0])) {

                int t = a[i][0];
                int x = a[i][1];
                int y = (j < b.size()) ? b[j][1] : 0;

                ans.push_back({t, x + y});
                i++;
            }
            else if (i == a.size() || b[j][0] < a[i][0]) {

                int t = b[j][0];
                int x = (i < a.size()) ? a[i][1] : 0;
                int y = b[j][1];

                ans.push_back({t, x + y});
                j++;
            }
            else {

                int t = a[i][0];
                ans.push_back({t, a[i][1] + b[j][1]});
                i++;
                j++;
            }
        }

        return ans;
    }
};