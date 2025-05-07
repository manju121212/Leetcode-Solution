class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>>res(n,vector<int>(m,1e9));

        
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int curr_time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
             if(x == n-1 && y == m-1){
                    return curr_time ;
                }
            pq.pop();
            
             for (int d = 0; d < 4; ++d) {
            int newx = x + dirs[d][0];
            int newy = y + dirs[d][1];
               
                if(newx >=0 && newy>=0 && newx<n && newy<m){
                      
                      int wait =max(moveTime[newx][newy] - curr_time,0);
                      int finalTime = wait + curr_time +1;
                      
                      if(res[newx][newy] > finalTime){
                           res[newx][newy] = finalTime;
                           pq.push({finalTime,{newx,newy}});
                      }
                      
                }
                
            }
        }

        return res[n-1][m-1];
    }
};