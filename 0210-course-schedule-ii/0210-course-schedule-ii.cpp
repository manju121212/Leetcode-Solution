class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           int n = prerequisites.size();
          vector<int>indegree(numCourses,0);
          unordered_map<int,list<int>>adj;
          for(int i = 0;i<prerequisites.size();i++){
                   int u = prerequisites[i][0];
                   int v = prerequisites[i][1];
                   adj[u].push_back(v);
                   adj[v].push_back(u);
                   indegree[u]++;
          }
          queue<int>q;
          for(int i = 0;i<numCourses;i++){
                 if(indegree[i] == 0 ){
                    q.push(i);
                 }
          }
          int count = 0;
          vector<int>res;
          while(!q.empty()){
               int node  = q.front();
               res.push_back(node);
               q.pop();
               count++;

               for(auto it :adj[node] ){
                     indegree[it]--;
                     if(indegree[it] == 0){
                           q.push(it);
                     }
               }
          }

          if(count == numCourses){
              
               return res;
          }
          return {};
    }
};