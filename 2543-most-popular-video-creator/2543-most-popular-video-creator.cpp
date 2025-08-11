class Solution {
public:
    typedef pair<int,string>T;
    struct cmp{

        bool operator()(const T&a , const T&b){
                if(a.first == b.first){
                      return a.second > b.second;
                }
                return a.first < b.first;
        }
    };
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        vector<vector<string>> ans;

        unordered_map<string,long long> gatherPoints;
        unordered_map<string, priority_queue<T,vector<T>,cmp>> gatherIds; // changed set → vector

        // Step 1: Gather total views
        for (int i = 0; i < n; i++) {
            gatherPoints[creators[i]] += views[i];
        }

        // Step 2: Store all (id, views) pairs, keeping duplicates
        for (int i = 0; i < n; i++) {
            gatherIds[creators[i]].push({ views[i],ids[i]});
        }

        // Step 3: Find max total views
        long long maxi = -1;
        for (auto &it : gatherPoints) {
            maxi = max(maxi, it.second);
        }

        unordered_map<string,bool> vis;

        // Step 4: For each creator with max total views, find their best video
        for (int i = 0; i < n; i++) {
            if (vis[creators[i]]) continue;

            long long points = gatherPoints[creators[i]];
            if (points == maxi) {
               string tt = gatherIds[creators[i]].top().second;
                
                ans.push_back({creators[i], tt});
            }
            vis[creators[i]] = true;
        }

        return ans;
    }
};
