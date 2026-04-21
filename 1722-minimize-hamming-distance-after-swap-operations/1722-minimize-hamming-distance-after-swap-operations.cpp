class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& component) {
        visited[node] = 1;
        component.push_back(node);

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, adj, visited, component);
            }
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

       
        vector<vector<int>> adj(n);
        for (auto &e : allowedSwaps) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);
        int result = 0;

        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);

                
                unordered_map<int, int> freq;
                for (int idx : component) {
                    freq[source[idx]]++;
                }

                
                for (int idx : component) {
                    if (freq[target[idx]] > 0) {
                        freq[target[idx]]--;
                    } else {
                        result++; 
                    }
                }
            }
        }

        return result;
    }
};