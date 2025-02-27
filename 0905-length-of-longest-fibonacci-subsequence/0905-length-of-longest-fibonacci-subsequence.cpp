

class Solution {
public:
    void solve(int k, int j, unordered_map<int, int>& mpp, vector<int>& arr, int res, int& maxLength) {
        
        int value = arr[k] - arr[j];

        if (mpp.find(value) != mpp.end()  && k>j && j>mpp[value]  ) {
            res += 1;
            maxLength = max(maxLength, res);
            solve(j, mpp[value], mpp, arr, res, maxLength);
        }
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> mpp;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            mpp[arr[i]] = i;
        }

        int maxLength = 0;
        for (int k = 2; k < n; k++) {
            for (int j = k - 1; j >= 0; j--) {
                int res = 2;
                solve(k, j, mpp, arr, res, maxLength);
            }
        }

        return maxLength >= 3 ? maxLength : 0;
    }
};


