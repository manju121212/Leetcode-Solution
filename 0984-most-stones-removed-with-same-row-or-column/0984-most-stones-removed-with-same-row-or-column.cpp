class Solution {
public:
    // Disjoint Set Union (Union-Find)
    int find(int x, vector<int> &parent) {
        if (parent[x] != x) 
            parent[x] = find(parent[x], parent); // path compression
        return parent[x];
    }

    void unite(int x, int y, vector<int> &parent, vector<int> &rank) {
        int px = find(x, parent);
        int py = find(y, parent);
        if (px == py) return;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[py] < rank[px]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int OFFSET = 10001;  // separate row and column space
        int MAX = 20005;     // slightly larger than max possible node index

        vector<int> parent(MAX), rank(MAX, 0);
        for (int i = 0; i < MAX; i++) parent[i] = i;

        unordered_set<int> used; // store nodes that appear (rows or cols)

        // Step 1: Union each stone’s row and column
        for (auto &s : stones) {
            int row = s[0];
            int col = s[1] + OFFSET;
            unite(row, col, parent, rank);
            used.insert(row);
            used.insert(col);
        }

        // Step 2: Count unique parents among used nodes
        unordered_set<int> uniqueParents;
        for (auto node : stones) {
            uniqueParents.insert(find(node[0], parent));
        }

        // Step 3: Stones that can be removed = total - number of components
        return stones.size() - uniqueParents.size();
    }
};
