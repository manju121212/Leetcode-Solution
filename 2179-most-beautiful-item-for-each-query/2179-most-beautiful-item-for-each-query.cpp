class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unordered_map<int,int> mpp;

        // Step 1: Keep only max beauty for each price
        for(auto& item : items){
            int price = item[0];
            int beauty = item[1];
            mpp[price] = max(mpp[price], beauty);
        }

        // Step 2: Put into a sorted vector
        vector<pair<int,int>> v;
        for(auto& [price, beauty] : mpp){
            v.push_back({price, beauty});
        }
        sort(v.begin(), v.end());

        // Step 3: Make prefix max of beauty
        for(int i = 1; i < v.size(); i++){
            v[i].second = max(v[i].second, v[i-1].second);
        }

        // Step 4: Answer each query
        vector<int> res;
        for(int q : queries){
            auto it = upper_bound(v.begin(), v.end(), make_pair(q, INT_MAX));
            if(it == v.begin()) {
                res.push_back(0); // no price <= q
            } else {
                --it;
                res.push_back(it->second);
            }
        }

        return res;
    }
};
