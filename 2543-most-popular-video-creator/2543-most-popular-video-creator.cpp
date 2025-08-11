class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        vector<vector<string>> ans;

        unordered_map<string,long long> gatherPoints;
        unordered_map<string, vector<pair<string,int>>> gatherIds; // changed set → vector

        // Step 1: Gather total views
        for (int i = 0; i < n; i++) {
            gatherPoints[creators[i]] += views[i];
        }

        // Step 2: Store all (id, views) pairs, keeping duplicates
        for (int i = 0; i < n; i++) {
            gatherIds[creators[i]].push_back({ids[i], views[i]});
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
                int ma = -1;
                string tt = "";
                for (const auto &val : gatherIds[creators[i]]) { // now loops over ALL videos
                    string id = val.first;
                    int v = val.second;

                    if (v > ma) {
                        tt = id;
                        ma = v;
                    }
                    else if (v == ma) {
                        if (tt > id) {
                            tt = id;
                        }
                    }
                }
                ans.push_back({creators[i], tt});
            }
            vis[creators[i]] = true;
        }

        return ans;
    }
};
