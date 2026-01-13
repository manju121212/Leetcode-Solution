class Solution {
public:
    #define P pair<int, int>

  
    void dijkstra(int n, unordered_map<int, vector<P>>& adj, vector<int>& result, int S) {
       
        for(int i=0;i<n;i++){
          result[i]=INT_MAX;
        }

        set<pair<int,int>>st;
        result[S] = 0;
        st.insert({0,S});

       while(!st.empty()){

            auto top= *(st.begin());
            int distance=top.first;
            int node=top.second;
            st.erase(st.begin());

            for(auto neighbour: adj[node]){
            
                if(result[node]+ neighbour.second < result[neighbour.first]){
                
                 auto record =  st.find(make_pair(result[neighbour.first],neighbour.first));
                
                    if(record!=st.end()){
                       st.erase(record);
                    }
                
                    result[neighbour.first]=result[node]+ neighbour.second;
                
                    st.insert(make_pair(  result[neighbour.first],neighbour.first));
                }
         }
    }
            
       }

    
    

    int getCityWithFewestReachable(int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;

       
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<P>> adj;

        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adj[start].push_back({end, weight});
            adj[end].push_back({start, weight});
        }

        // Compute shortest paths from each city using Dijkstra's algorithm
        for (int i = 0; i < n; i++) {
            dijkstra(n, adj, shortestPathMatrix[i], i);
        }

        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
};

