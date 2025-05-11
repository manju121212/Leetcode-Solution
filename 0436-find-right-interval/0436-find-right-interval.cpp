class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Step 1: Store {start, original index}
        vector<pair<int, int>> sortedStarts;
        for (int i = 0; i < n; i++) {
            sortedStarts.push_back({intervals[i][0], i});
        }

        // Step 2: Sort by start
        sort(sortedStarts.begin(), sortedStarts.end());

        vector<int> res(n, -1);

        // Step 3: For each interval, find the lower_bound of its end
        for (int i = 0; i < n; i++) {
            int end_i = intervals[i][1];
            pair<int, int> target = {end_i, 0};

            auto it = lower_bound(sortedStarts.begin(), sortedStarts.end(), target);

            if (it != sortedStarts.end()) {
                res[i] = it->second;
            }
        }

        return res;
    }
};
