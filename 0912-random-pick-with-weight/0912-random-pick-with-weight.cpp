

class Solution {
    std::vector<int> prefixSums;
    int totalSum;

public:
    Solution(std::vector<int>& w) {
        prefixSums.resize(w.size());
        prefixSums[0] = w[0];
        for (int i = 1; i < w.size(); ++i) {
            prefixSums[i] = prefixSums[i - 1] + w[i];
        }
        totalSum = prefixSums.back();
    }

    int pickIndex() {
        int target = rand() % totalSum + 1; 
        return std::lower_bound(prefixSums.begin(), prefixSums.end(), target) - prefixSums.begin();
    }
};
