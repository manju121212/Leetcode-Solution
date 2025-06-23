

class Solution {
public:
    int count = 0;  // To count number of nodes whose cost we increased

    // Adjacency list for the tree
    vector<vector<int>> tree;

    // DFS function to return the max score from current node to any leaf
    long long dfs(int node, int parent, vector<int>& cost) {
        long long maxPath = 0;
        vector<long long> childPaths;

        for (int child : tree[node]) {
            if (child == parent) continue;  // Skip parent in undirected tree
            long long childPath = dfs(child, node, cost);
            childPaths.push_back(childPath);
            maxPath = max(maxPath, childPath);
        }

        // If this is a leaf node, just return its own cost
        if (childPaths.empty()) return cost[node];

        // Bring all child paths up to maxPath by increasing node costs
        for (long long path : childPaths) {
            if (path < maxPath) {
                count++;  // We had to increase a node (in the child subtree)
            }
        }

        // Return total path from this node to leaf (current cost + max child path)
        return cost[node] + maxPath;
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        // Build the adjacency list for the tree
        tree.resize(n);
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        // Start DFS from root (node 0)
        dfs(0, -1, cost);

        return count;
    }
};
