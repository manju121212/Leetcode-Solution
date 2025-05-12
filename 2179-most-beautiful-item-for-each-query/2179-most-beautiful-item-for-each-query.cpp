class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        vector<pair<int,int>>v;
        unordered_map<int,int>mpp;

        for(int i = 0; i < items.size(); i++) {
            int a = items[i][0];
            int b = items[i][1];
            v.push_back({a,b});
           
        }

      

        sort(v.begin(), v.end());

        // Make prefix max of beauty
        for(int i = 1; i < v.size(); i++) {
            v[i].second = max(v[i].second, v[i - 1].second);
        }

        vector<int> res(queries.size(), 0);
        for(int i = 0; i < queries.size(); i++) {
            pair<int,int> target = {queries[i], INT_MAX}; // INT_MAX ensures proper upper_bound
            int index = upper_bound(v.begin(), v.end(), target) - v.begin();

            if(index == 0) {
                res[i] = 0; // No item with price <= query
            } else {
                res[i] = v[index - 1].second; // Use the max beauty up to index - 1
            }
        }

        return res;
    }
};
