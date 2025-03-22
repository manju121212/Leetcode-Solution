class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string,int>supp_store;
        vector<int>indegree(recipes.size(),0);
        unordered_map<string,int>getIndex;
       unordered_map<string,list<string>>adj;
        vector<string>res;

        for(int i = 0;i<recipes.size();i++){
            getIndex[recipes[i]] = i;
        }
        for(int i = 0;i<supplies.size();i++){
               supp_store[supplies[i]]++;
        }
        queue<int>q;

        for(int i = 0;i<recipes.size();i++){
              
              for(int j = 0;j<ingredients[i].size();j++){
                   
                   if(supp_store.find(ingredients[i][j]) == supp_store.end()){
                          indegree[i]++;
                          adj[ingredients[i][j]].push_back(recipes[i]);
                   }
              }
        }


        for(int i = 0;i<indegree.size();i++){
               if(indegree[i] == 0){
                q.push(i);
               }
        }



        while(!q.empty()){
            
            int index_recp = q.front();
            q.pop();

            res.push_back(recipes[index_recp]);


            for(auto it : adj[recipes[index_recp]]){
                   int neigh_index = getIndex[it];
                   indegree[neigh_index]--;
                   if(indegree[neigh_index] == 0){
                       q.push(neigh_index);
                   }
            }
            


             


        }

        return res;
    }
};