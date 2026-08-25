class Solution {
public:

    int m, n;
    vector<vector<int>> dp;

    int dfs(int i, int j, vector<vector<int>>& dungeon) {

        // Destination
        if (i == m - 1 && j == n - 1) {
            return max(1, 1 - dungeon[i][j]);
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = INT_MAX;
        int right = INT_MAX;

        // Go DOWN
        if (i + 1 < m) {
            down = dfs(i + 1, j, dungeon);
        }

        // Go RIGHT
        if (j + 1 < n) {
            right = dfs(i, j + 1, dungeon);
        }

        // Choose the path requiring less health
        int need = min(down, right);

        // Calculate health required before entering current cell
        dp[i][j] = max(1, need - dungeon[i][j]);

        return dp[i][j];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        m = dungeon.size();
        n = dungeon[0].size();

        dp.assign(m, vector<int>(n, -1));

        return dfs(0, 0, dungeon);
    }
};