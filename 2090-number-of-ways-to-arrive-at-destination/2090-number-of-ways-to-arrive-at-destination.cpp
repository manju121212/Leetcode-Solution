#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
      
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

       
        vector<long long> dist(n, LLONG_MAX);
       
        vector<int> ways(n, 0);

       
        set<pair<long long, int>> st;
        dist[0] = 0;
        ways[0] = 1;
        st.insert({0, 0});

        while (!st.empty()) {
            auto [currTime, node] = *st.begin();
            st.erase(st.begin());

            for (auto [nextNode, edgeTime] : adj[node]) {
                long long newTime = currTime + edgeTime;

              
                if (newTime < dist[nextNode]) {
                    st.erase({dist[nextNode], nextNode}); 
                    dist[nextNode] = newTime;
                    ways[nextNode] = ways[node]; 
                    st.insert({newTime, nextNode});
                }
               
                else if (newTime == dist[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1]; 
    }
};
