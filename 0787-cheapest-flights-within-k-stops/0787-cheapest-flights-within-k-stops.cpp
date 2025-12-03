class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>>adjlist;

        for(int i =0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int c = flights[i][2];
            adjlist[u].push_back({v,c});  
           
        }  
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dest(n,INT_MAX);
        dest[src] = 0;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int stops = front.first;
            int node = front.second.first;
            int cost = front.second.second;

           
            if(stops >k){
                continue;
            }
            for(auto neighbour:adjlist[node]){
              int adjnode = neighbour.first;
              int weight = neighbour.second;
              
              if(weight + cost < dest[adjnode]  ){
                  dest[adjnode] = weight + cost;
                  q.push({stops+1,{adjnode,weight+cost}});
              }

            }

        }
      if(dest[dst] == INT_MAX){
          return -1;
      }
      else{
          return dest[dst];
      }
       
    }
};