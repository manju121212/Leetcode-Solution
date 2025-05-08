class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        
       int dirs[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
       int n = moveTime.size();
       int m = moveTime[0].size();

       priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;


        pq.push({0,{0,0,1}});
        vector<vector<int>>res(n,vector<int>(m,INT_MAX));
        while(!pq.empty()){
            int curr_time = pq.top().first;
            int x = pq.top().second[0];
            int y = pq.top().second[1];
            int time_count = pq.top().second[2];
            pq.pop();
      
            if(x == n-1 && y == m-1){
                return curr_time;
            }
          

            for(int d = 0;d<4;d++){
                int newx = x + dirs[d][0];
                int newy = y + dirs[d][1];

                if(newx>=0 && newy>=0 && newx<n && newy<m){
                    
                     int wait = max(moveTime[newx][newy] - curr_time,0);
                    
                     int finalTime = wait + curr_time +time_count;
                     
                     int inc_count = time_count  ==2 ? 0 : 1;
                    
                     
                   
                     if(res[newx][newy] > finalTime){
                        
                    
                        res[newx][newy] = finalTime;
                        pq.push({finalTime,{newx,newy,inc_count+1}});
                     }
                }
            }
            
        }

        return -1;
    }
};