class Solution {
public:

    int solve(int node, int cost,
              unordered_map<int, list<pair<int,int>>>& mpp,
              unordered_map<int,int>& best, int &distanceThreshold,
              unordered_set<int>& counted) {

        int res = 0;

        for (auto &it : mpp[node]) {
            int nxt = it.first;
            int w   = it.second;
            int newCost = cost + w;

            if (newCost > distanceThreshold) continue;

            // Only proceed if this path is better
            if (!best.count(nxt) || newCost < best[nxt]) {

                best[nxt] = newCost;

                // Count this city only once
                if (!counted.count(nxt)) {
                    counted.insert(nxt);
                    res += 1;
                }

                res += solve(nxt, newCost, mpp, best, distanceThreshold, counted);
            }
        }

        return res;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        unordered_map<int,list<pair<int,int>>> mpp;

        for (auto &it : edges) {
            int u = it[0], v = it[1], w = it[2];
            mpp[u].push_back({v,w});
            mpp[v].push_back({u,w});
        }

        int mini = INT_MAX;
        int ele  = -1;

        for (int i = 0; i < n; i++) {

            unordered_map<int,int> best;
            best[i] = 0;

            unordered_set<int> counted;

            int ans = solve(i, 0, mpp, best, distanceThreshold, counted);

            cout << i << " -> " << ans << endl;

            if (ans < mini || (ans == mini && i > ele)) {
                mini = ans;
                ele  = i;
            }
        }

        return ele;
    }
};
