class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> mini(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
       

        while (!pq.empty()) {
            int current_time = pq.top().first;
           
            int x = pq.top().second.first, y = pq.top().second.second;
             pq.pop();

            if (x == n - 1 && y == m - 1) return current_time;

            for (auto [xi, yi] : vector<pair<int, int>>{{x + 1, y}, {x, y + 1}, {x - 1, y}, {x, y - 1}}) {
                if (xi >= 0 && xi < n && yi >= 0 && yi < m && vis[xi][yi] == false) {
                    int wt = max(0, moveTime[xi][yi] - current_time);
                    int temp = current_time + wt + 1;
                   vis[xi][yi] = true;
                    pq.push({temp, {xi, yi}});
                
                }
            }
        }
        return -1;
    }
};