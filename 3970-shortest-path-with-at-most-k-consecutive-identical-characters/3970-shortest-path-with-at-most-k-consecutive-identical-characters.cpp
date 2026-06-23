
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
         vector<vector<pair<int,int>>> g(n);

        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
        }

        long long inf = 1e18;

        vector<vector<long long>> distance(n, vector<long long>(k + 1, inf));

        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > pq;

        distance[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            long long d = cur[0];
            int u = cur[1];
            int cnt = cur[2];

            if (d != distance[u][cnt]) continue;

            for (auto &p : g[u]) {
                int v = p.first;
                int w = p.second;

                int ncnt = 1;

                if (labels[u] == labels[v]) {
                    ncnt = cnt + 1;
                }

                if (ncnt > k) continue;

                long long nd = d + w;

                if (nd < distance[v][ncnt]) {
                    distance[v][ncnt] = nd;
                    pq.push({nd, v, ncnt});
                }
            }
        }

        long long result = inf;

        for (int i = 1; i <= k; i++) {
            result = min(result, distance[n - 1][i]);
        }

        return result == inf ? -1 : result;
    }
};