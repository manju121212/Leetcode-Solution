class Solution {
public:
void solve(int node , unordered_map<int,list<int>>&mpp,vector<bool>&vis ){
          
           vis[node] = true;
         

           for(auto it : mpp[node]){
               if(vis[it] == false){
                   solve(it,mpp,vis);
               }
           }


    }
    int findCircleNum(vector<vector<int>>& isConnected) {
           
           unordered_map<int,list<int>>mpp;
           int provinces = 0;
           int n = isConnected.size();
           vector<bool>vis(n,false);
           for(int i = 0;i<n;i++){
               for(int j = 0;j<n;j++){
                   if(i!=j && isConnected[i][j] == 1){
                          mpp[i].push_back(j);
                   }
               }
           }


           for(int i = 0;i<n;i++){
                 if(vis[i] == false){
                       provinces++;
                       solve(i,mpp,vis);
                 }
           }

           return provinces;
    }
};