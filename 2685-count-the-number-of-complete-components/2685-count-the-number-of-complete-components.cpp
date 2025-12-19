class Solution {
public:
    void dfs(int node  , unordered_map<int,list<int>>&adj , vector<bool>&vis,int &c_nodes , int &c_vertices ){
         
         vis[node] = true;
         c_nodes++;
         for(auto it : adj[node]){
            c_vertices++;
            if(vis[it] == false){
                 
                  dfs(it,adj,vis,c_nodes,c_vertices);
            }
          
            
         }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
          

          unordered_map<int,list<int>>adj;
      
          for(int i = 0;i<edges.size();i++){
             
             adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
            
          }

          int count = 0;
          vector<bool>vis(n,false);
          for(int i = 0;i<n;i++){
             
              int c_nodes = 0;
              int c_vertices = 0;
              if(vis[i] == false){
                    dfs(i,adj,vis,c_nodes,c_vertices);
                      cout<<i<<":"<<"nodes"<<c_nodes<<" "<<"vertices"<<c_vertices<<endl;

                      int total_edges = (c_nodes*(c_nodes-1))/2;
                      if(c_nodes == 1){
                          count++;
                      }
                      else if(total_edges == c_vertices/2){
                        count++;
                      }
              }
          }

          return count;
    }
};