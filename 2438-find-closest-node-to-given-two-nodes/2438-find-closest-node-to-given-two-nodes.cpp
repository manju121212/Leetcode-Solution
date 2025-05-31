class Solution {
public:
    void dfs(int node , unordered_map<int,int>&adj , unordered_map<int,int>&mpp,vector<bool>&vis,int depth){
        vis[node] = true;
        mpp[node] = depth;

        if (adj.count(node)) {
            int it = adj[node];
            if(vis[it] == false){
                dfs(it,adj,mpp,vis,depth+1);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,int> adj;
        int n = edges.size();

        // Build adjacency list
        for(int i = 0; i < n; i++) {
            if(edges[i] != -1) {
                adj[i] = edges[i];
            }
        }

        unordered_map<int,int> mpp1, mpp2;
        vector<bool> vis1(n, false), vis2(n, false);
        dfs(node1, adj, mpp1, vis1, 0);
        dfs(node2, adj, mpp2, vis2, 0);

        int minDist = INT_MAX;
        int result = -1;

        for(int i = 0; i < n; i++) {
            if(mpp1.count(i) && mpp2.count(i)) {
                int maxDist = max(mpp1[i], mpp2[i]);
                if(maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                } else if(maxDist == minDist && i < result) {
                    result = i;
                }
            }
        }

        return result;
    }
};
