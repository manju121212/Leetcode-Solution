class Solution {
public:
    void solve(int node , unordered_map<int,list<int>>&mpp,vector<bool>&vis,int &count ){
           count++;
           vis[node] = true;
         

           for(auto it : mpp[node]){
               if(vis[it] == false){
                   solve(it,mpp,vis,count);
               }
           }


    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,list<int>>mpp;
       
        for(int i = 0;i<rooms.size();i++){
             for(auto it : rooms[i]){
                  mpp[i].push_back(it);
             }
               
               
        }
        int n = rooms.size();
         vector<bool>vis(n,false);
        int count = 0;
        solve(0,mpp,vis,count);
        cout<<count<<endl;
        if(count == n){
              return true;
        }
        return false;

    }
};