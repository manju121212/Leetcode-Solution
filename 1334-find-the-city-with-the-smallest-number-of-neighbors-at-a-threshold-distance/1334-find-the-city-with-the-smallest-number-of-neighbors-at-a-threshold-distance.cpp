class Solution {
public:

    void solve(int node , int w,
               unordered_map<int,list<pair<int,int>>>&mpp,
               vector<int>&dist,
               int &distanceThreshold){

        for(auto it : mpp[node]){

            int next = it.first;
            int weight = it.second;

            if(w + weight <= distanceThreshold && w + weight < dist[next]){

                dist[next] = w + weight;

                solve(next, w + weight, mpp, dist, distanceThreshold);
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        unordered_map<int,list<pair<int,int>>>mpp;

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            mpp[u].push_back({v,w});
            mpp[v].push_back({u,w});
        }

        int res = INT_MAX;
        int ele = -1;

        for(int i = 0;i<n;i++){

            vector<int>dist(n,INT_MAX);
            dist[i] = 0;

            solve(i,0,mpp,dist,distanceThreshold);

            int count = 0;

            for(int j=0;j<n;j++){
                if(i!=j && dist[j] <= distanceThreshold)
                    count++;
            }

            if(count <= res){
                res = count;
                ele = i;
            }
        }

        return ele;
    }
};