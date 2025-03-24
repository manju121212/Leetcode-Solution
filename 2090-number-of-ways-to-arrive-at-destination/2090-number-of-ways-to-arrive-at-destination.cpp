class Solution {
public:
    int solve(unordered_map<int, list<pair<int, int>>>& adj, vector<long long>& dist, int n) {
        const int MOD = 1e9 + 7;

        dist[0] = 0;
        set<pair<long long, int>> s;
        s.insert({0, 0});
        
        vector<int> min_ways_dest(n, 0);
        min_ways_dest[0] = 1;

        while (!s.empty()) {
            auto top = *(s.begin());
            int node = top.second;
            long long w = top.first;
            s.erase(s.begin());

            for (auto it : adj[node]) {
                int nextNode = it.first;
                long long newTime = dist[node] + it.second;

                // Found a shorter path
                if (newTime < dist[nextNode]) {
                    auto record = s.find({dist[nextNode], nextNode});
                    if (record != s.end()) s.erase(record);

                    dist[nextNode] = newTime;
                    min_ways_dest[nextNode] = min_ways_dest[node]; // Inherit path count
                    s.insert({dist[nextNode], nextNode});
                }
                // If another shortest path is found, add to ways count
                else if (newTime == dist[nextNode]) {
                    min_ways_dest[nextNode] = (min_ways_dest[nextNode] + min_ways_dest[node]) % MOD;
                }
            }
        }

        return min_ways_dest[n - 1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, list<pair<int, int>>> adj;

        for (auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        return solve(adj, dist, n);
    }
};
