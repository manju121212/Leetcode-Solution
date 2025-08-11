
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        vector<vector<string>> ans;

        unordered_map<string,long long> gatherPoints;

        // custom comparator: highest views first, then smallest id
        struct cmp {
            bool operator()(const pair<string,int>& a, const pair<string,int>& b) const {
                if (a.second != b.second) return a.second > b.second; // more views first
                return a.first < b.first; // lexicographically smaller id first
            }
        };

        unordered_map<string, set<pair<string,int>, cmp>> gatherIds;

        for (int i = 0; i < n; i++) {
            gatherPoints[creators[i]] += views[i];
        }

        for (int i = 0; i < n; i++) {
            gatherIds[creators[i]].insert({ids[i], views[i]});
        }

        long long maxi = -1;
        for (auto it : gatherPoints) {
            maxi = max(maxi, it.second);
        }

        unordered_map<string,bool> vis;
        for (int i = 0; i < n; i++) {
            if (vis[creators[i]]) continue;

            long long points = gatherPoints[creators[i]];
            if (points == maxi) {
                // first element in set will be the one with highest views, smallest id
                string tt = gatherIds[creators[i]].begin()->first;
                ans.push_back({creators[i], tt});
            }
            vis[creators[i]] = true;
        }

        return ans;
    }
};
