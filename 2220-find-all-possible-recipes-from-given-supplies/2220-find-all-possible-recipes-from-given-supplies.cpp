class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
       unordered_map<string,int>mpp;
       vector<string>res;
       for(int i = 0;i<supplies.size();i++){
           mpp[supplies[i]]++;
       }
       queue<int>q;
       for(int i = 0;i<recipes.size();i++){
            q.push(i);
       }
       
       while(true){
            int n = q.size();
            int m = mpp.size();
            for(int i = 0;i<n;i++){
                    int index_recipe = q.front();
                    q.pop();
                    bool flag = true;
                    for(int j = 0;j<ingredients[index_recipe].size();j++){
                            
                            string avail = ingredients[index_recipe][j];
                            if(mpp.find(avail) == mpp.end()){
                                flag = false;
                                q.push(index_recipe);
                                break;
                            }
                    }

                    if(flag == true){
                        res.push_back(recipes[index_recipe]);
                        mpp[recipes[index_recipe]]++;
                    }
            }

            if(mpp.size()>m ){
                continue;
            }
            else{
                break;
            }

       

       }

       return res;
    }
};