class Solution {
public:
    int cnt = 0;
    void dfs(int node , int k , int dist,unordered_map<int,list<int>>&adj, vector<bool>&vis){
         vis[node] = true;
         if(dist>k){
            return ;
         }
         cnt++;

         for(auto it : adj[node]){
             if(vis[it] == false){
                 dfs(it , k,dist+1,adj,vis);
             }
         }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        unordered_map<int,list<int>>adj1;
        unordered_map<int,list<int>>adj2;
        int maxi = 0;
        vector<int>res(n,0);
        for(auto it : edges1){
               int u = it[0];
               int v = it[1];
               adj1[u].push_back(v);
               adj1[v].push_back(u);

        }

          for(auto it : edges2){
               int u = it[0];
               int v = it[1];
               adj2[u].push_back(v);
               adj2[v].push_back(u);
               
        }

        for(int i = 0;i<m;i++){
            cnt = 0;
             vector<bool> vis(m);
            dfs(i,k-1,0,adj2,vis);
            maxi = max(maxi , cnt);
        }

        for(int i = 0;i<n;i++){
            cnt = 0;
             vector<bool> vis(n);
            dfs(i,k,0,adj1,vis);
            res[i] = cnt + maxi;
        }

        return res;
    }
};