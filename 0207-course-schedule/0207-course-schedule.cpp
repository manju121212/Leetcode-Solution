class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>indegree(numCourses,0);
        unordered_map<int,list<int>>adj;

        for(auto it : prerequisites){
              int u = it[0];
              int v = it[1];
              indegree[u]++;
              adj[u].push_back(v);
               adj[v].push_back(u);
        }
        queue<int>q;
        for(int i= 0;i<numCourses;i++){
              if(indegree[i] == 0){
                   q.push(i);
              }
        }


        if(q.empty()){
             return false;
        }
        int count = 0;
        while(!q.empty()){
               int node = q.front();
               q.pop();
               count++;
               for(auto it : adj[node]){
                     indegree[it]--;
                     if(indegree[it] == 0){
                         q.push(it);
                     }
               }

        }

        if(count<numCourses){
            return false;
        }

        return true;


         
    }
};