class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);

        int result = 0;
        minDist[0] = 0;

        for (int edges = 0; edges < n; edges++) {
            int curr = -1;

            
            for (int i = 0; i < n; i++) {
                if (!inMST[i] && (curr == -1 || minDist[i] < minDist[curr])) {
                    curr = i;
                }
            }

            inMST[curr] = true;
            result += minDist[curr];

           
            for (int next = 0; next < n; next++) {
                if (!inMST[next]) {
                    int cost = abs(points[curr][0] - points[next][0]) +
                               abs(points[curr][1] - points[next][1]);

                    minDist[next] = min(minDist[next], cost);
                }
            }
        }

        return result;
    }
};