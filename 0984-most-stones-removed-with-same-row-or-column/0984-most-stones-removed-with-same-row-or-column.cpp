class Solution {
public:
    void dfs(int node, unordered_map<int, list<int>> &mpp, unordered_set<int> &vis) {
        vis.insert(node);
        for (auto &nbr : mpp[node]) {
            if (!vis.count(nbr)) dfs(nbr, mpp, vis);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, list<int>> mpp;
        int OFFSET = 10001;

        for (auto &s : stones) {
            int u = s[0];
            int v = s[1] + OFFSET;
            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        unordered_set<int> vis;
        int components = 0;

        for (auto &s : stones) {
            int u = s[0];
            if (!vis.count(u)) {
                components++;
                dfs(u, mpp, vis);
            }
        }

        return stones.size() - components;
    }
};
