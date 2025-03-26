class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        int n = grid.size(), m = grid[0].size();

        // Flatten grid into 1D array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp.push_back(grid[i][j]);
            }
        }

        sort(temp.begin(), temp.end());  // O(N log N)
        int median = temp[temp.size() / 2];  // Choose median

        int operations = 0;
        for (int num : temp) {
            int diff = abs(num - median);
            if (diff % x != 0) return -1;  // If conversion is not possible
            operations += diff / x;
        }

        return operations;
    }
};
