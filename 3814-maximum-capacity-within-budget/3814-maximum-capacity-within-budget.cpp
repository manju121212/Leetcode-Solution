class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({costs[i], capacity[i]});
        }

        sort(v.begin(), v.end());

        vector<int> pre(n);
        pre[0] = v[0].second;
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], v[i].second);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int rem = budget - v[i].first;
            if (rem <= 0) continue;

            ans = max(ans, v[i].second);

            int low = 0, high = i - 1, ind = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (v[mid].first < rem) {
                    ind = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (ind != -1) {
                ans = max(ans, v[i].second + pre[ind]);
            }
        }

        return ans;
    }
};