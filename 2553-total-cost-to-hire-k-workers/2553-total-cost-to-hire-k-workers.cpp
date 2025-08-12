class Solution {
public:
    typedef pair<int,int> P; // {cost, index}
    struct cmp {
        bool operator()(const P &a, const P &b) const {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };

    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0, right = n - 1;
        long long total = 0;

        priority_queue<P, vector<P>, cmp> pq1, pq2;

        // Fill first candidates from left
        for (int i = 0; i < candidates && left <= right; i++) {
            pq1.push({costs[left], left});
            left++;
        }
        // Fill first candidates from right
        for (int i = 0; i < candidates && left <= right; i++) {
            pq2.push({costs[right], right});
            right--;
        }

        while (k-- > 0) {
            // Decide which heap to take from
            if (pq2.empty() || (!pq1.empty() && pq1.top() <= pq2.top())) {
                auto [cost, idx] = pq1.top(); pq1.pop();
                total += cost;
                if (left <= right) {
                    pq1.push({costs[left], left});
                    left++;
                }
            } else {
                auto [cost, idx] = pq2.top(); pq2.pop();
                total += cost;
                if (left <= right) {
                    pq2.push({costs[right], right});
                    right--;
                }
            }
        }
        return total;
    }
};
