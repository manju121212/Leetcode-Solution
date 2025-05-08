class Solution {
public:
  typedef pair<int, pair<int, int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        
       int dirs[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
       int n = moveTime.size();
       int m = moveTime[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;
       

        pq.push({0,{0,0}});
        vector<vector<int>>res(n,vector<int>(m,INT_MAX));
         res[0][0] = 0;
        
        while(!pq.empty()){
            int curr_time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            pq.pop();
      
            if(x == n-1 && y == m-1){
                return curr_time;
            }
          

            for(int d = 0;d<4;d++){
                int newx = x + dirs[d][0];
                int newy = y + dirs[d][1];

                if(newx>=0 && newy>=0 && newx<n && newy<m){
                     int time_count = (newx + newy)%2 == 0 ? 2 : 1;
                   
                   
                     int wait = max(moveTime[newx][newy] - curr_time,0);
                    
                     int finalTime = wait + curr_time +time_count;
                     
                    
                    
                     
                   
                     if(res[newx][newy] > finalTime){
                         
                    
                        res[newx][newy] = finalTime;
                        pq.push({finalTime,{newx,newy}});
                     }
                }
            }
            
            
        }

        return -1;
    }
};